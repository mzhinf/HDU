/*
    �����γ�ʱԭ��:�������ڵ���ͨ��ʱ�� û��ѡȡ���ڵ� ���¼��ϳɻ� �޷��ҵ���ʵ���ڵ�
*/

//#define LOCAL
#include <cstdio>

//Union-Find ���鼯 start----------
int id[2005],opp[2005];
bool flag;

void first(int n){//��ʼ������
    flag = false;
    for (int i = 0; i <= n; i++){ id[i] = i; opp[i] = 0; }//��ʼ��id
}

int find(int p){//Ѱ��p�ĸ��ڵ�
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

void love(int p,int q){
    int i = find(p);//��ȡp���ڵ�
    int j = find(q);//��ȡq���ڵ�
    if (i == j){
        flag=true;//����ͬ����
        return;
    }
    if(opp[i])id[opp[i]]=j;
    if(opp[j])id[opp[j]]=i;
    opp[i]=j;
    opp[j]=i;
}
//Union-Find ���鼯 end ----------

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
