/*
    对于 a b c d
	(a-b)^2+(c-d)^2< (a-c)^2+(b-d)^2
	(a-b)^2+(c-d)^2< (a-d)^2+(b-c)^2
	
	故必须进行排序


	dp 类似背包 对于第i对数是否选择
	
	dp[n][k] n个数选k对 最小疲劳值
	
	对于第i件货物是否搬运
	不搬
	dp[i][j] = dp[i-1][j];
	
    搬
    dp[i][j] = dp[i-2][j-1] + tired[i-1];
	
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int tired[2005];
int dp[2005][2005];

int main(){
    int n,k;
    //freopen("data.in","r",stdin);
    while(~scanf("%d%d",&n,&k)){
        for(int i=1;i<=n;i++)scanf("%d",&tired[i]);
        sort(tired+1,tired+n+1);
        for(int i=1;i<n;i++){
            tired[i] = tired[i+1] - tired[i];
            tired[i] *= tired[i];
        }
        dp[0][0]=0;
        for(int i=1;i<=n;i++){//第1件到第n件是否选择
            int temp=(i+1)/2;
            for(int j=1;j<=k&&j*2<=i;j++){
                dp[i][j] = dp[i-2][j-1] + tired[i-1];
                if(j<temp)dp[i][j] = min(dp[i][j],dp[i-1][j]);
            }
        }
        printf("%d\n",dp[n][k]);
    }
    return 0;
}

