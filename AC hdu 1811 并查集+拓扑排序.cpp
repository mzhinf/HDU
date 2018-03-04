/*
	1 0
	OK
	注意N,M的范围 两个整数N,M(0<=N<=10000,0<=M<=20000) N，M可能等于0
*/
//#define LOCAL
#include <cstdio>
#include <cstring>
#include <malloc.h>
#include <algorithm>
#include <queue>
using namespace std;
queue<int> st;
//邻接表
struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
};
struct VNode {
	int csnum;
	ArcNode firstarc;
}v[10005];
bool vmap[10005];//表示i是否被访问
bool s[10005];//表示i是否被记录(数据中是否存在)

//记录输入数据
int a[20005],b[20005];
char c[20005][2];

//并查集
int id[10005];
int ucount;

//判断最终情况
bool cflag=false,uflag=false;


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
	if (i == j)return ;
	id[j] = i;
	ucount--;//p q合并 减少一个集合
}
void first(int n){//初始化函数
	ucount = n;
	for (int i = 0; i < n; i++){ id[i] = i; v[i].firstarc.nextarc=NULL; v[i].csnum=0;}//初始化id
	memset(vmap,0,sizeof(vmap));
	memset(s,0,sizeof(s));
	cflag=false,uflag=false;
	while(st.size())st.pop();
}
//visit
void visit(int i){
	v[i].csnum--;
	ArcNode *p=v[i].firstarc.nextarc;
	for(int i;p!=NULL;p=p->nextarc){
		i=p->adjvex;
		i==find(i);
		v[i].csnum--;
		if(v[i].csnum!=0||vmap[i])continue;
		else st.push(i);
		vmap[i]=true;
	}
}
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        //freopen("data.out","w",stdout);
    #endif
    int n,m;
	ArcNode *p;//每次创建的结点
    while(~scanf("%d%d",&n,&m)){//n 0--n-1
    	if(n==0){
    		printf("OK\n");continue;
    	}
    	else if(n==1&&m==0){
    		printf("OK\n");continue;
    	}
    	first(n);
    	//输入信息 合并等于
		for(int i=0;i<m;i++){
			scanf("%d%s%d",&a[i],c[i],&b[i]);
			s[a[i]]=1;
			s[b[i]]=1;
			if(c[i][0]=='='){
				merge(a[i],b[i]);continue;
			}
			else if(c[i][0]=='<')swap(a[i],b[i]);
		}
		//输入路径信息
		for(int i=0;i<m;i++){
			if(c[i][0]!='='){//a[i] > b[i]
				p=(ArcNode *) malloc (sizeof(ArcNode));
				p->nextarc=NULL;
				int ta=find(a[i]);//ta>tb
				int tb=find(b[i]);
				p->adjvex=tb;
				p->nextarc=v[ta].firstarc.nextarc;
				v[ta].firstarc.nextarc=p;
				v[tb].csnum++;//ta->tb tb前驱加一
			}
		}
		//拓扑排序
		for(int i=0;i<n;i++){
			int t=find(i);
			if(v[t].csnum!=0||vmap[t])continue;
			else st.push(t);
			vmap[t]=true;
		}
		while(st.size()){
			if(st.size()>1)uflag=true;
			visit(st.front());
			st.pop();
		}
		//判断情况
		for(int k=0;k<n;k++){
			if(!s[k]){//存在未录入
				uflag=true;
			}
			int t=find(k);
			if(!vmap[t]){//存在环
				cflag=true;
				break;
			}
		}
		if(cflag)
			printf("CONFLICT\n");
		else if(uflag)
			printf("UNCERTAIN\n");
		else
			printf("OK\n");
    }
    return 0;
}
