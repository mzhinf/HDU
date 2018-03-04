//#define LOCAL
#include <cstdio>
#include <set>
using namespace std;

//Union-Find 并查集 start----------
int id[100005],h[100005]; //id[i]表示i的父节点 h[i]表示i的高度
int ucount; //连通集个数
bool flag;
set<int> map;

void first(int n){//初始化函数
	ucount=0;
	flag = false;
	for (int i = 1; i <= n; i++){ id[i] = i;h[i] = 1; }//初始化id 与 树高h
	map.clear();
}

int find(int p){//寻找p的根节点
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

void merge(int p, int q){//连通p q (合并p q的集合)
	int i = find(p);//获取p根节点
	int j = find(q);//获取q根节点
	if (i == j){
		flag=true;//存在成环现象
		return;//根节点相同 不用连接
	}

	if     (h[i] == h[j]){ id[j] = i; h[i]++; }//一样高则i为根 j做子树
	else if(h[i] >  h[j]){ id[j] = i; }//i高 j做子树
	else                 { id[i] = j; }//j高 i做子树
	ucount--;//p q合并 减少一个集合
}

bool connected(int p, int q){ return find(p) == find(q); }//p q是否连通 (p q是否在同一个集合)
//Union-Find 并查集 end ----------

int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int a,b;
	while(~scanf("%d%d",&a,&b)){
		if(a==-1&&b==-1)break;
		else if(a==0&&b==0){
			printf("Yes\n");
			continue;
		}
		else{
			first(100001);
			merge(a,b);
			map.insert(a);
			map.insert(b);
		}
		while(~scanf("%d%d",&a,&b)){
			if(a==0&&b==0)break;
			else if(flag==1)continue;
			merge(a,b);
			map.insert(a);
			map.insert(b);
		}
		if(flag==1||(ucount+map.size())!=1)
			printf("No\n");
		else
			printf("Yes\n");
	}
    return 0;
}
