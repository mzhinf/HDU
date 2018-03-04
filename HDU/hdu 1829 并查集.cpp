/*
    本题多次超时原因:在两个节点连通的时候 没有选取根节点 导致集合成环 无法找到真实根节点
*/

//#define LOCAL
#include <cstdio>

//Union-Find 并查集 start----------
int id[2005],opp[2005];
bool flag;

void first(int n){//初始化函数
    flag = false;
    for (int i = 0; i <= n; i++){ id[i] = i; opp[i] = 0; }//初始化id
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

void love(int p,int q){
    int i = find(p);//获取p根节点
    int j = find(q);//获取q根节点
    if (i == j){
        flag=true;//存在同性恋
        return;
    }
    if(opp[i])id[opp[i]]=j;
    if(opp[j])id[opp[j]]=i;
    opp[i]=j;
    opp[j]=i;
}
//Union-Find 并查集 end ----------

int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,m,x,y;
        scanf("%d%d",&n,&m);
        first(n);
        while(m--){
            scanf("%d%d",&x,&y);
            if(!flag)love(x,y);
        }
        printf("Scenario #%d:\n",i);
        if(flag)
            printf("Suspicious bugs found!\n\n");
        else
            printf("No suspicious bugs found!\n\n");
    }
    return 0;
}
