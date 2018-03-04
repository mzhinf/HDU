//正确做法 dp背包
//#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double dp[10000];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        //freopen("data.out","w",stdout);
    #endif
    int m,n;
	while(~scanf("%d%d",&n,&m)){
		if(m==0&&n==0)break;
		int ai;
		double bi;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<m;i++){
			scanf("%d%lf",&ai,&bi);
			for(int i=n;i>=ai;i--){
				dp[i]=max(dp[i],1.0-(1.0-dp[i-ai])*(1.0-bi));
			}
		}
		double p=0;
		for(int i=0;i<=n;i++){
			if(dp[i]>p)p=dp[i];
		}
		printf("%.1lf%%\n",p*100);
	}
	return 0;
}
/*
//	举个反例：
//	sample:
//	10  4
//	5  0.5
//	4  0.4
//	3  0.3
//	2  0.2
//	贪心运行结果为：70.0%  选5、4
//	而DP正确结果：72.0%  选5、3、2

//错误做法 贪心
//#define LOCAL
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct offer{
	int ai;
	double bi;
	double m;
}map[10005];
const double eps = 1e-10;//
int dcmp(double x){ if(fabs(x) < eps) return 0; else return x < 0 ? -1 :1; }//减少精度问题
bool cmp(const offer& a,const offer& b){
	if(a.m<b.m)return true;
	else if(dcmp(a.m-b.m)){
		if(a.ai>b.bi)return true;
	}
	return false;
}
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        //freopen("data.out","w",stdout);
    #endif
    int m,n;
	while(~scanf("%d%d",&m,&n)){
		if(m==0&&n==0)break;
		for(int i=0;i<n;i++){
			scanf("%d%lf",&map[i].ai,&map[i].bi);
			map[i].m=map[i].ai/map[i].bi;
		}
		sort(map,map+n,cmp);
		double p=1;
		for(int i=0;i<n&&m>0;i++){
			if(m>=map[i].ai){
				m-=map[i].ai;
				p*=(1-map[i].bi);
			}
		}
		printf("%.1lf%%\n",(1-p)*100);
	}
	return 0;
}
*/
