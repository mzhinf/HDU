//#define LOCAL
#include <cstdio>
int map[105];
double dp[105][2];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int l,n,c,t,vr,vt1,vt2;
    while(~scanf("%d",&l)){
        scanf("%d%d%d",&n,&c,&t);
        scanf("%d%d%d",&vr,&vt1,&vt2);
        for(int i=1;i<=n;i++){
            scanf("%d",&map[i]);
        }
        map[0]=0;map[n+1]=l;
        dp[0][0]=0;dp[0][1]=c;
        for(int i=1;i<=n+1;i++){
            int smin=0;
            for(int j=0;j<i;j++){
                int temp=map[i]-map[i-1];
                if(temp<dp[j][1]){
                    dp[j][0]+=1.0*temp/vt1;
                    dp[j][1]-=temp;
                }
                else{
                    dp[j][0]+=1.0*dp[j][1]/vt1+1.0*(temp-dp[j][1])/vt2;
                    dp[j][1]=0;
                }
                if(dp[j][0]<dp[smin][0])smin=j;
            }
            dp[i][0]=dp[smin][0]+t;
            dp[i][1]=c;
        }
        if(dp[n+1][0]-t<l*1.0/vr)
            printf("What a pity rabbit!\n");
        else
            printf("Good job,rabbit!\n");
    }
    return 0;
} 