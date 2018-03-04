//#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[105][105];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
	while(n--){
	    int t,temp;
	    scanf("%d",&t);
	    memset(dp,0,sizeof(dp));
		for(int i=1;i<=t;i++){
			for(int j=1;j<=i;j++){
				scanf("%d",&temp);
				dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+temp;
			}
		}
		int smax=-1;
		for(int i=1;i<=t;i++){
			if(dp[t][i]>smax)smax=dp[t][i];
		}
		printf("%d\n",smax);
	}
    return 0;
}
