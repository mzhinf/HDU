/*
    分析1:n个格子不考虑头尾同色有3*2^(n-1)种 n个格子头尾同色相当于(n-1)个格子头尾不同色
    故:dp[n]=3*2^(n-1)-dp[n-1];
    dp[0]=1,dp[1]=3,dp[2]=6;
    
    分析2:n个格子涂色可对第n-1个格子进行分类
          1.第n-1与第一个个格子不同色(dp[n-1]) 此时第n个格子只有一种情况 dp[n-1]
          2.第n-1与第一个个格子同色(dp[n-2])   此时第n个格子有两种情况 2*dp[n-2]
    故:dp[n]=dp[n-1]+2*dp[n-2];
    dp[0]=1,dp[1]=3,dp[2]=6,dp[3]=6;
*/
//#define LOCAL
#include <cstdio>
#include <cmath>
long long dp[51];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n;
	dp[0]=1,dp[1]=3,dp[2]=6;
	for(int i=3;i<51;i++)dp[i]=3*pow(2,i-1)-dp[i-1];
	while(~scanf("%d",&n)){
		printf("%I64d\n",dp[n]);
	}
    return 0;
}
