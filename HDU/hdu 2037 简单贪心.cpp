/*
    以i事件结尾的最大事件数 = 在i前能发生的最大事件数 + 1
	le[i]=max(le[i],le[j]+1);
*/
//#define LOCAL
#include <cstdio>
#include <algorithm>
using namespace std;
struct P{
	int b;
	int e;
}p[105];
bool cmp(const P& a,const P& b){
	if(a.b<b.b)return true;
	else if(a.b==b.b&&a.e<=b.e)return true;
	else return false;
}
int le[105];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        //freopen("data.out","w",stdout);
    #endif
    int n;
	while(~scanf("%d",&n)&&n!=0){
		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i].b,&p[i].e);
		}
		sort(p,p+n,cmp);
		int smax=0;
		for(int i=0;i<n;i++){
			le[i]=1;
			for(int j=i-1;j>-1;j--){
				if(p[i].b>=p[j].e){
					le[i]=max(le[i],le[j]+1);
				}
			}
			if(smax<le[i])smax=le[i];
		}
		printf("%d\n",smax);
	}
    return 0;
}
