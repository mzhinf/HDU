/*
    注意端点的相交 本题端点相交也算相交
*/
//#define LOCAL
#include <cstdio>

//计算几何
#include <cmath>
struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
}p[1005][2];
typedef Point Vector;
const double eps = 1e-10;
Vector operator - (Point A, Point B){ return Vector(A.x-B.x,A.y-B.y); }
double Dot(Vector A, Vector B){ return A.x*B.x+A.y*B.y; }
int dcmp(double x){ if(fabs(x) < eps) return 0; else return x < 0 ? -1 :1; }//减少精度问题
double Cross(Vector A, Vector B){ return A.x*B.y-A.y*B.x; }
bool operator == (const Point& a, const Point& b){ return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0; }
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){
	double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1),
		   c3 = Cross(b2-b1,a1-b1), c4 = Cross(b2-b1,a2-b1);
	return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
bool OneSegment(Point p,Point a1,Point a2){
	return dcmp(Cross(a1-p,a2-p)) == 0 && dcmp(Dot(a1-p,a2-p)) < 0;
}
//并查集
int id[1005],h[1005]; //id[i]表示i的根节点 h[i]表示i集合数目
int num; //id个数

void init(int n){//初始化函数
	num = 1;
	for (int i = 1; i <= n; i++){ id[i] = i;h[i] = 1; }//初始化id 与 树高h
}
int find(int p){//寻找p的根节点 O(logN)
	int r=id[p];
	while (r != id[r])r=id[r];//循环找到根节点
	int f;//父节点
	while (p != r){
		f=id[p];//获取父节点
		id[p]=r;//修改该节点
        p=f;//循环修改父节点
	}
	return r;
}
void merge(int p, int q){//连通p q (合并p q的集合) O(1)
	int i = find(p);//获取p根节点
	int j = find(q);//获取q根节点
	if(i == j)return;//根节点相同 不用连接
	if(h[i] >= h[j]){ id[j] = i; h[i]+=h[j]; }//一样高则i为根 j做子树
	else            { id[i] = j; h[j]+=h[i]; }//j为根 i做子树
}

int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        //freopen("data.out","w",stdout);
    #endif
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		char c[5];
		scanf("%d",&n);
		init(1001);
		while(n--){
			scanf("%s",c);
			if(c[0]=='P'){
				scanf("%lf%lf%lf%lf", &p[num][0].x, &p[num][0].y, &p[num][1].x, &p[num][1].y);
				for(int i=1;i<num;i++){//1-num
					if(SegmentProperIntersection(p[i][0],p[i][1],p[num][0],p[num][1])){
						//printf("%d %d\n",i,num);
						merge(i,num);
					}
					else if(OneSegment(p[num][0],p[i][0],p[i][1]))merge(i,num);
					else if(OneSegment(p[num][1],p[i][0],p[i][1]))merge(i,num);
					else if(p[num][0]==p[i][0] || p[num][0]==p[i][1] ||
							p[num][1]==p[i][0] || p[num][1]==p[i][1] )merge(i,num);
				}
				num++;
			}
			else if(c[0]=='Q'){
				int temp;
				scanf("%d",&temp);
				temp=find(temp);
				printf("%d\n",h[temp]);
			}
		}
		if(t)printf("\n");
	}
    return 0;
}
