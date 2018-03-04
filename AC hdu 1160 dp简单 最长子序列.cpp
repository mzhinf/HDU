/*
    w体重递增 s速度递减
    体重排序降序排序 + 速度最长递减子序列
*/
//从前到后dp 最长递减子序列
//#define LOCAL
#include <cstdio>
#include <algorithm>
using namespace std;
struct Mouse{
    int pos;
    int w;
    int s;
};
bool cmp(const Mouse& a,const Mouse& b){
    if(a.w<b.w)return true;
    else if(a.w==b.w){
        if(a.s>b.s)
            return true;
        else
            return false;
    }
    else return false;
}
Mouse m[10005];
int dp[10005][2];//dp[i][0] 放i结尾的最长子序列的长度 dp[i][1] 放i的前一个位点 0代表前面无位点
int print[10005];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    //输入
    int n;
    for(n=1;~scanf("%d%d",&m[n].w,&m[n].s);n++){
        m[n].pos=n;
    }
    n--;
    //排序
    sort(m+1,m+n+1,cmp);
    /*
    for(int i=1;i<=n;i++){
        printf("%d %d %d\n",m[i].pos,m[i].w,m[i].s);
    }
    */
    //最长降序子序列
    int smax=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=1;dp[i][1]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(m[j].s>m[i].s&&m[j].w!=m[i].w){//降序
                if(dp[j][0]+1>dp[i][0]){
                    dp[i][0]=dp[j][0]+1;
                    dp[i][1]=j;
                }
            }
        }
        if(dp[i][0]>dp[smax][0])smax=i;
    }
    //输出
    n=dp[smax][0];
    for(int i=0;smax!=0;i++){
        print[i]=m[smax].pos;
        smax=dp[smax][1];
    }
    printf("%d\n",n);
    for(int i=n-1;i>-1;i--){
        printf("%d\n",print[i]);
    }
    return 0;
}
/*
//从后到前dp 最长递增子序列
//#define LOCAL
#include <cstdio>
#include <algorithm>
using namespace std;
struct Mouse{
	int pos;
	int w;
	int s;
};
bool cmp(const Mouse& a,const Mouse& b){
	if(a.w<b.w)return true;
	else if(a.w==b.w){
		if(a.s>b.s)
			return true;
		else
			return false;
	}
	else return false;
}
Mouse m[10005];
int dp[10005][2];//dp[i][0] 放i结尾的最长子序列的长度 dp[i][1] 放i的前一个位点 0代表前面无位点
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n;
	for(n=1;~scanf("%d%d",&m[n].w,&m[n].s);n++){
		m[n].pos=n;
	}
	n--;
	sort(m+1,m+n+1,cmp);
	//最长递增子序列
	int smax=1;
	for(int i=n;i>0;i--){
		dp[i][0]=1;dp[i][1]=0;
	}
	for(int i=n;i>0;i--){
		for(int j=n;j>i;j--){
			if(m[j].s<m[i].s&&m[j].w!=m[i].w){
				if(dp[j][0]+1>dp[i][0]){
					dp[i][0]=dp[j][0]+1;
					dp[i][1]=j;
				}
			}
		}
		if(dp[i][0]>dp[smax][0])smax=i;
	}
	printf("%d\n",dp[smax][0]);
	for(int i=0;smax!=0;i++){
		printf("%d\n",m[smax].pos);
		smax=dp[smax][1];
	}
    return 0;
}
*/
