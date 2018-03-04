/*
    ����1:n�����Ӳ�����ͷβͬɫ��3*2^(n-1)�� n������ͷβͬɫ�൱��(n-1)������ͷβ��ͬɫ
    ��:dp[n]=3*2^(n-1)-dp[n-1];
    dp[0]=1,dp[1]=3,dp[2]=6;
    
    ����2:n������Ϳɫ�ɶԵ�n-1�����ӽ��з���
          1.��n-1���һ�������Ӳ�ͬɫ(dp[n-1]) ��ʱ��n������ֻ��һ����� dp[n-1]
          2.��n-1���һ��������ͬɫ(dp[n-2])   ��ʱ��n��������������� 2*dp[n-2]
    ��:dp[n]=dp[n-1]+2*dp[n-2];
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
