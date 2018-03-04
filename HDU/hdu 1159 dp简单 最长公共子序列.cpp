//#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[1000];
char b[1000];
int dp[1000][1000];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    while(~scanf("%s %s",a,b)){
    	for(int i=0;i<strlen(a);i++){
    		for(int j=0;j<strlen(b);j++){
    			if(a[i]==b[j]){
    				if(i==0||j==0)dp[i][j]=1;
    				else dp[i][j]=dp[i-1][j-1]+1;
    			}
    			else{
    				if(i==0){
    					if(j==0)dp[i][j]=0;
    					else dp[i][j]=dp[i][j-1];
    				}
					else if(j==0){
						dp[i][j]=dp[i-1][j];
					}
					else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    			}
    		}
    	}
    	printf("%d\n",dp[strlen(a)-1][strlen(b)-1]);
    }
    return 0;
}
