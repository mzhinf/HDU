/*
	分割平面空间问题(4)
*/
//#define LOCAL
#include <cstdio>
int dp[1005][2];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    dp[1][0]=2;
    dp[1][1]=2;
	for(int i=2;i<1005;i++){
		dp[i][0]=dp[i-1][0]+i;
		dp[i][1]=dp[i-1][1]+dp[i-1][0];
	}
	
	int n;
	while(~scanf("%d",&n)){
		printf("%d\n",dp[n][1]);
	}
    return 0;
}
