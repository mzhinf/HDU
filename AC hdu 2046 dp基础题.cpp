/*
	分析:
    n可分为 前n-1加一个竖 前n-2加两个横
    
    dp[i]=dp[i-1]+dp[i-2]
    
    dp[1]=1,dp[2]=2;
*/
//#define LOCAL
#include <cstdio>
long long dp[51];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n;
    dp[1]=1,dp[2]=2;
	for(int i=3;i<=50;i++)dp[i]=dp[i-1]+dp[i-2];
	while(~scanf("%d",&n)){
		printf("%I64d\n",dp[n]);
	}
    return 0;
}
