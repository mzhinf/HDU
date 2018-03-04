/*
    ����������,����Ϊ��һ�����겻�ƶ�Ҳ���Խ�ס3��λ����ڱ�

    dp[t][i] ����t��ʱi���ܼ�������ڱ���
    ��dp[t][i]=t��ʱ��i���õ��ڱ���+ǰһ���ܵ���i������ڱ���
    dp[t][i]=map[t][i]+max(dp[t-1][i-1],dp[t-1][i],dp[t-1][i+1])

    ��������: i-1>=0 i+1<=10
	���ƹ涨: dp[t][i]=-1 ��ʾ�õ㲻����Ϊ������

*/
//�ⷨ1 Exe.Time:93MS Exe.Memory:10328K �������� д���е��鷳
//#define LOCAL
#include <cstdio>
#include <cstring>
int map[100005][11];
int dp[100005][11];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n;
    while(~scanf("%d",&n)&&n!=0){
    	int pos,t,T=0;
    	memset(map,0,sizeof(map));
    	while(n--){
    		scanf("%d %d",&pos,&t);
			map[t][pos]++;
			if(t>T)T=t;
    	}
    	for(int i=0;i<11;i++){
    		dp[1][i]=-1;
    	}
    	dp[1][4]=map[1][4];
    	dp[1][5]=map[1][5];
    	dp[1][6]=map[1][6];
    	int mmax,dmax;
    	for(int i=2;i<=T;i++){//��i��
    		for(int j=0;j<11;j++){//jλ��
				mmax=dmax=-1;
                for(int k=-1;k<2;k++){
                	if(j+k<0||j+k>10)continue;
					if(dmax<dp[i-1][j+k])dmax=dp[i-1][j+k];
                }
                if(dmax!=-1){
                	dp[i][j]=dmax+map[i][j];
                }
                else dp[i][j]=-1;
    		}
    	}
    	int smax=-1;
    	for(int i=0;i<11;i++){
    		if(dp[T][i]>smax)smax=dp[T][i];
    		//printf("%d ",dp[T][i]);
    	}
    	//printf("\n");
    	printf("%d\n",smax);
    }
    return 0;
}

/*
//�ⷨ2 Exe.Time:62MS Exe.Memory:6020K
//dp[i][j] ����i�뿪ʼ��j����� �ܼƻ������ڱ���
//��dp[i][j]=i��ʱ��j���õ��ڱ���+��j������һ���ܻ������ڱ���
//dp[i][j]=map[i][j]+max(dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]);

//#define LOCAL
#include <cstdio>
#include <cstring>
int dp[100005][11];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n;
    while(~scanf("%d",&n)&&n!=0){
    	int pos,t,T=0;
    	memset(dp,0,sizeof(dp));
    	while(n--){
    		scanf("%d %d",&pos,&t);
			dp[t][pos]++;
			if(t>T)T=t;
    	}
    	for(int i=T-1;i>=0;i--){//��i��
    		for(int j=0;j<11;j++){//jλ��
				int dmax=0;
                for(int k=-1;k<2;k++){
                	if(j+k<0||j+k>10)continue;
					if(dmax<dp[i+1][j+k])dmax=dp[i+1][j+k];//ѡ��3��λ�����ֵ
                }
                dp[i][j]+=dmax;
    		}
    	}
    	printf("%d\n",dp[0][5]);
    }
    return 0;
}
*/
