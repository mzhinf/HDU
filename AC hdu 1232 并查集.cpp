//#define LOCAL
#include <cstdio>

//Union-Find 并查集 start----------
#define N 1000
int id[N],h[N]; //id[i]表示i的父节点 h[i]表示i的高度
int count; //连通集个数
void first(int n){//初始化函数
	count = n;
	for (int i = 1; i <= n; i++){ id[i] = i;h[i] = 1; }//初始化id 与 树高h
}
int find(int p){
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
void merge(int p, int q){
	int i = find(p);//获取p根节点
	int j = find(q);//获取q根节点
	if (i == j) return;//根节点相同 不用连接

	if     (h[i] == h[j]){ id[j] = i; h[i]++; }//一样高则i为根 j做子树
	else if(h[i] >  h[j]){ id[j] = i; }//i高 j做子树
	else                 { id[i] = j; }//j高 i做子树
	count--;//p q合并 减少一个集合
}
bool connected(int p, int q){ return find(p) == find(q); }//p q 是否连通
//Union-Find 并查集 end ----------

int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n,m;
    while(~scanf("%d",&n)&&n!=0){
    	first(n);
    	scanf("%d",&m);
    	int x,y;
    	for(int i=0;i<m;i++){
    		scanf("%d%d",&x,&y);
    		merge(x,y);
    	}
    	printf("%d\n",count-1);
    }
    return 0;
}
