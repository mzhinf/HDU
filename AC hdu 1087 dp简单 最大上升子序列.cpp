//#define LOCAL
#include <cstdio>
int dp[1005][2];//dp[i][0]第i个数的值
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n;
	while(~scanf("%d",&n)&&n!=0){
	    //最大上升子序列
		for(int i=0;i<n;i++){
			scanf("%d",&dp[i][0]);
			dp[i][1]=dp[i][0];
			for(int j=0;j<i;j++){
				if(dp[i][0]>dp[j][0]){
					if(dp[i][1]<dp[j][1]+dp[i][0])
						dp[i][1]=dp[j][1]+dp[i][0];
				}
			}
		}
		int smax=dp[0][1];
		for(int i=1;i<n;i++){
			if(smax<dp[i][1])smax=dp[i][1];
		}
		printf("%d\n",smax);
	}
    return 0;
}
