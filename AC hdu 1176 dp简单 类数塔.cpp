/*
    题意理解错误,误认为在一个坐标不移动也可以接住3个位点的馅饼

    dp[t][i] 代表t秒时i点总计最大获得馅饼数
    则dp[t][i]=t秒时在i点获得的馅饼数+前一秒能到达i的最大馅饼数
    dp[t][i]=map[t][i]+max(dp[t-1][i-1],dp[t-1][i],dp[t-1][i+1])

    限制条件: i-1>=0 i+1<=10
	限制规定: dp[t][i]=-1 表示该点不能作为出发点

*/
//解法1 Exe.Time:93MS Exe.Memory:10328K 从上至下 写的有点麻烦
//#define LOCAL
#include <cstdio>
#include <cstring>
int map[100005][11];
int dp[100005][11];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n;
    while(~scanf("%d",&n)&&n!=0){
    	int pos,t,T=0;
    	memset(map,0,sizeof(map));
    	while(n--){
    		scanf("%d %d",&pos,&t);
			map[t][pos]++;
			if(t>T)T=t;
    	}
    	for(int i=0;i<11;i++){
    		dp[1][i]=-1;
    	}
    	dp[1][4]=map[1][4];
    	dp[1][5]=map[1][5];
    	dp[1][6]=map[1][6];
    	int mmax,dmax;
    	for(int i=2;i<=T;i++){//第i秒
    		for(int j=0;j<11;j++){//j位置
				mmax=dmax=-1;
                for(int k=-1;k<2;k++){
                	if(j+k<0||j+k>10)continue;
					if(dmax<dp[i-1][j+k])dmax=dp[i-1][j+k];
                }
                if(dmax!=-1){
                	dp[i][j]=dmax+map[i][j];
                }
                else dp[i][j]=-1;
    		}
    	}
    	int smax=-1;
    	for(int i=0;i<11;i++){
    		if(dp[T][i]>smax)smax=dp[T][i];
    		//printf("%d ",dp[T][i]);
    	}
    	//printf("\n");
    	printf("%d\n",smax);
    }
    return 0;
}

/*
//解法2 Exe.Time:62MS Exe.Memory:6020K
//dp[i][j] 代表i秒开始从j点出发 总计获得最大馅饼数
//则dp[i][j]=i秒时在j点获得的馅饼数+从j出发后一秒能获得最大馅饼数
//dp[i][j]=map[i][j]+max(dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]);

//#define LOCAL
#include <cstdio>
#include <cstring>
int dp[100005][11];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n;
    while(~scanf("%d",&n)&&n!=0){
    	int pos,t,T=0;
    	memset(dp,0,sizeof(dp));
    	while(n--){
    		scanf("%d %d",&pos,&t);
			dp[t][pos]++;
			if(t>T)T=t;
    	}
    	for(int i=T-1;i>=0;i--){//第i秒
    		for(int j=0;j<11;j++){//j位置
				int dmax=0;
                for(int k=-1;k<2;k++){
                	if(j+k<0||j+k>10)continue;
					if(dmax<dp[i+1][j+k])dmax=dp[i+1][j+k];//选择3个位点最大值
                }
                dp[i][j]+=dmax;
    		}
    	}
    	printf("%d\n",dp[0][5]);
    }
    return 0;
}
*/
