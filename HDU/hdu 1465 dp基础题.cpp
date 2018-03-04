/*

    分析:
    当有n封错装可以分为 前n-1封错装 前n-2封错装
    前n-1封错装 可以由任意一封与第n封对调 f(n-1)*(n-1)
    前n-2封错装 可以由未错装的与第n封对调 f(n-2)*(n-1)

	错排公式:
	f(n)=(f(n-1)+f(n-2))*(n-1);
	
	f(1)=0,f(2)=1;
*/
//#define LOCAL
#include <cstdio>
long long dp[21];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n;
    //初始化
    dp[1]=0,dp[2]=1;
	for(int i=3;i<=20;i++)dp[i]=(dp[i-1]+dp[i-2])*(i-1);
	while(~scanf("%d",&n)){
		printf("%I64d\n",dp[n]);
	}
    return 0;
}
