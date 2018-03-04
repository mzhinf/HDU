/*
	树形dp
	树上的任意一点的取舍可以看成一种决策

	状态:
	dp[i][0]为不取该点时 以改点为根的子树的最大的活动值
	dp[i][1]为取该点

	状态转移方程:
	dp[i][0]+=max(dp[j][0],dp[j][1]);	//不取i的时候对于i的子节点j可以取也可以不取
	dp[i][1]+=dp[j][0];					//取i的时候则不能取子节点j

	对于根节点
	dp[i][0]=0;
	dp[i][1]=vitality;

	实现:
	邻接表存储数据与活动值
	
	代码详情
	Pro.ID	Exe.Time	Exe.Memory	Code Len.
	1520	124MS		1916K		1457 B
	存在内存释放(手动控制内存)
*/
//#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct arcNode{
	int ID;//
	arcNode *nextArc;
};

struct vNode{
	int ID;//号码
	int vitality;//活力值
	arcNode *firstArc;
};

vNode person[6005];
int dp[6005][2];
bool visit[6005];

void solve(int i);

int main(){
	#ifdef LOCAL
		freopen("data.in", "r", stdin);
		freopen("data.out", "w", stdout);
	#endif
	arcNode *temp;
	int n,a,b,flag;
	while(~scanf("%d",&n)){
		memset(visit,0,sizeof(visit));
		for(int i=1;i<=n;i++){
			scanf("%d",&person[i].vitality);
			person[i].ID=i;
			person[i].firstArc=NULL;
		}
		while(~scanf("%d%d",&a,&b)){//a是b的子树
			if(a==0&&b==0)break;
			temp=(arcNode *)malloc(sizeof(arcNode));
			temp->ID=a;
			temp->nextArc=person[b].firstArc;
			person[b].firstArc=temp;
		}
		for(int i=1;i<=n;i++){
			if(!visit[i]){
				solve(i);
				flag=i;
			}
		}
		printf("%d\n",max(dp[flag][0],dp[flag][1]));
	}
	return 0;
}
void solve(int i){
	arcNode *temp=person[i].firstArc,*p;
	//准备为下一次计算
	person[i].firstArc=NULL;
	//每个节点的提前工作
	dp[i][0]=0;
	dp[i][1]=person[i].vitality;
	//检查该节点是不是根节点
	if(temp==NULL){
		visit[i]=true;
		return ;
	}
	for(;temp!=NULL;){
		int j=temp->ID;
		if(!visit[j])solve(j);
		dp[i][0]+=max(dp[j][0],dp[j][1]);
		dp[i][1]+=dp[j][0];
		//释放数据
		p=temp->nextArc;
		free(temp);
		temp=p;
	}
	visit[i]=true;
}
