/*
    统计走廊的重叠次数 最大次数就是搬运次数 时间为最大次数*10
*/
//#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int map[205];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        //freopen("data.out","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    while(t--){
    	int n,a,b;;
		scanf("%d",&n);
		memset(map,0,sizeof(map));
		for(int i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			a=(a-1)/2;
			b=(b-1)/2;
			if(a>b)swap(a,b);
			for(int j=a;j<=b;j++){
				map[j]++;
			}
		}
		int smax=0;
		for(int i=0;i<200;i++){
			if(smax<map[i])smax=map[i];
		}
		printf("%d\n",smax*10);
    }
    return 0;
}
