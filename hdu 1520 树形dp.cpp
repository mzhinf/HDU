/*
	����dp
	���ϵ�����һ���ȡ����Կ���һ�־���

	״̬:
	dp[i][0]Ϊ��ȡ�õ�ʱ �Ըĵ�Ϊ�������������Ļֵ
	dp[i][1]Ϊȡ�õ�

	״̬ת�Ʒ���:
	dp[i][0]+=max(dp[j][0],dp[j][1]);	//��ȡi��ʱ�����i���ӽڵ�j����ȡҲ���Բ�ȡ
	dp[i][1]+=dp[j][0];					//ȡi��ʱ������ȡ�ӽڵ�j

	���ڸ��ڵ�
	dp[i][0]=0;
	dp[i][1]=vitality;

	ʵ��:
	�ڽӱ�洢������ֵ
	
	��������
	Pro.ID	Exe.Time	Exe.Memory	Code Len.
	1520	124MS		1916K		1457 B
	�����ڴ��ͷ�(�ֶ������ڴ�)
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
	int ID;//����
	int vitality;//����ֵ
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
		while(~scanf("%d%d",&a,&b)){//a��b������
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
	//׼��Ϊ��һ�μ���
	person[i].firstArc=NULL;
	//ÿ���ڵ����ǰ����
	dp[i][0]=0;
	dp[i][1]=person[i].vitality;
	//���ýڵ��ǲ��Ǹ��ڵ�
	if(temp==NULL){
		visit[i]=true;
		return ;
	}
	for(;temp!=NULL;){
		int j=temp->ID;
		if(!visit[j])solve(j);
		dp[i][0]+=max(dp[j][0],dp[j][1]);
		dp[i][1]+=dp[j][0];
		//�ͷ�����
		p=temp->nextArc;
		free(temp);
		temp=p;
	}
	visit[i]=true;
}
