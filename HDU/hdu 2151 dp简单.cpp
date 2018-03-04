//#define LOCAL
#include <cstdio>
#include <cstring>
int dp[105][105];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int N,P,M,T;
	while(~scanf("%d%d%d%d",&N,&P,&M,&T)){
		memset(dp,0,sizeof(dp));
		dp[0][P]=1;
		for(int i=1;i<=M;i++){
			for(int j=1;j<=N;j++){
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
			}
		}
		printf("%d\n",dp[M][T]);
	}
    return 0;
}
