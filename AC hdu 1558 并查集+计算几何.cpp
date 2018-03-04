/*
    ע��˵���ཻ ����˵��ཻҲ���ཻ
*/
//#define LOCAL
#include <cstdio>

//���㼸��
#include <cmath>
struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
}p[1005][2];
typedef Point Vector;
const double eps = 1e-10;
Vector operator - (Point A, Point B){ return Vector(A.x-B.x,A.y-B.y); }
double Dot(Vector A, Vector B){ return A.x*B.x+A.y*B.y; }
int dcmp(double x){ if(fabs(x) < eps) return 0; else return x < 0 ? -1 :1; }//���پ�������
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
//���鼯
int id[1005],h[1005]; //id[i]��ʾi�ĸ��ڵ� h[i]��ʾi������Ŀ
int num; //id����

void init(int n){//��ʼ������
	num = 1;
	for (int i = 1; i <= n; i++){ id[i] = i;h[i] = 1; }//��ʼ��id �� ����h
}
int find(int p){//Ѱ��p�ĸ��ڵ� O(logN)
	int r=id[p];
	while (r != id[r])r=id[r];//ѭ���ҵ����ڵ�
	int f;//���ڵ�
	while (p != r){
		f=id[p];//��ȡ���ڵ�
		id[p]=r;//�޸ĸýڵ�
        p=f;//ѭ���޸ĸ��ڵ�
	}
	return r;
}
void merge(int p, int q){//��ͨp q (�ϲ�p q�ļ���) O(1)
	int i = find(p);//��ȡp���ڵ�
	int j = find(q);//��ȡq���ڵ�
	if(i == j)return;//���ڵ���ͬ ��������
	if(h[i] >= h[j]){ id[j] = i; h[i]+=h[j]; }//һ������iΪ�� j������
	else            { id[i] = j; h[j]+=h[i]; }//jΪ�� i������
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
