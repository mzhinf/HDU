//#define LOCAL
#include <cstdio>

//Union-Find 并查集 start----------
int id[2550],h[2550]; //id[i]表示i的根节点 h[i]表示i的高度
int re[2550][4];
int ucount; //连通集个数 使用count要注意

void first(int n){//初始化函数
	ucount = n;
	for (int i = 0; i < n; i++){ id[i] = i;h[i] = 1; re[i][0]=re[i][1]=re[i][2]=re[i][3]=-1; }//初始化id 与 树高h
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
	if (i == j)return;//根节点相同 不用连接
	if     (h[i] == h[j]){ id[j] = i; h[i]++; }//一样高则i为根 j做子树
	else if(h[i] >  h[j]){ id[j] = i; }//i高 j做子树
	else                 { id[i] = j; }//j高 i做子树
	ucount--;//p q合并 减少一个集合
}

bool connected(int p, int q){ return find(p) == find(q); }//p q是否连通 (p q是否在同一个集合)
//Union-Find 并查集 end ----------

//id=n*i+j
int dir[5][2]={{},{-1,0},{0,1},{1,0},{0,-1}};//上 1 右 2 下 3 左 4
int c[11][4]={{1,4},{1,2},{3,4},{2,3},{1,3},{2,4},{1,2,4},{1,3,4},{2,3,4},{1,2,3},{1,2,3,4}};
char str[51][51];


int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int m,n;
	while(~scanf("%d%d",&m,&n)){
		if(m==-1&&n==-1)break;
		first(n*m);
		for(int i=0;i<m;i++)scanf("%s",str[i]);
		int temp,p,q;
		for(int i=0;i<m;i++){//行 m
			for(int j=0;j<n;j++){//列 n
				p=n*i+j;//(i,j) id
				temp=str[i][j]-'A';
				for(int k=0;c[temp][k]!=0&&k<4;k++){//获取地形A-K 转化成连接方向
					int ti=i+dir[c[temp][k]][0];
					int tj=j+dir[c[temp][k]][1];
					if(ti<0||ti>=m||tj<0||tj>=n)continue;//判断地形是否可连接
					q=n*ti+tj;
					re[p][k]=q;
					for(int l=0;l<4;l++){
						if(re[q][l]==p){
							merge(p,q);break;
						}
					}
				}
			}
		}
		printf("%d\n",ucount);
	}
    return 0;
}
