/*

    ����:
    ����n���װ���Է�Ϊ ǰn-1���װ ǰn-2���װ
    ǰn-1���װ ����������һ�����n��Ե� f(n-1)*(n-1)
    ǰn-2���װ ������δ��װ�����n��Ե� f(n-2)*(n-1)

	���Ź�ʽ:
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
    //��ʼ��
    dp[1]=0,dp[2]=1;
	for(int i=3;i<=20;i++)dp[i]=(dp[i-1]+dp[i-2])*(i-1);
	while(~scanf("%d",&n)){
		printf("%I64d\n",dp[n]);
	}
    return 0;
}
