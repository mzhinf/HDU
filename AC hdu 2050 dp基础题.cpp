/*
	分割平面空间问题(2)
*/
//#define LOCAL
#include <cstdio>
int dp[10005];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    dp[1]=2;
	for(int i=2;i<10001;i++)dp[i]=dp[i-1]+4*(i-1)+1;
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		printf("%d\n",dp[temp]);
	}
    return 0;
}
