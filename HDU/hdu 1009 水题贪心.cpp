//#define LOCAL
#include <cstdio>
#include <algorithm>
using namespace std;
struct sset{
	int j;
	int f;
	double l;
}map[1005];
bool cmp(const sset& a,const sset& b){
	return a.l>b.l;
}
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int m,n;
	while(~scanf("%d%d",&m,&n)){
		if(m==-1&&n==-1)break;
		for(int i=0;i<n;i++){
			scanf("%d%d",&map[i].j,&map[i].f);
			map[i].l=1.0*map[i].j/map[i].f;
		}
		sort(map,map+n,cmp);
		double sum=0;
		for(int i=0;i<n;i++){
			if(m>=map[i].f){
				m-=map[i].f;
				sum+=map[i].j;
			}
			else{
				sum+=(1.0*m/map[i].f*map[i].j);
				break;
			}
		}
		printf("%.3lf\n",sum);
	}
    return 0;
}
