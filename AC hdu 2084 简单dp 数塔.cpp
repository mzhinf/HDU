//#define LOCAL
#include <cstdio>
#include <cstring>
int max(int a,int b){
	return a>b?a:b;
}
int dp[105][105];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int t,n;
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	memset(dp,0,sizeof(dp));
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=i;j++){
    			scanf("%d",&dp[i][j]);
    		}
    	}
    	for(int i=n-1;i>0;i--){
    		for(int j=i;j>0;j--){
    			dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
    		}
    	}
    	printf("%d\n",dp[1][1]);
    }
    return 0;
}
