//#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct X{
    int x,y,z;
};
bool cmp(const X& a,const X& b){
    if(a.x>b.x)return true;
    else if(a.x==b.x){
        if(a.y>b.y)
            return true;
        else
            return false;
    }
    else return false;
}
X map[100];
int dp[100];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n,x,y,z,count=0;
    while(~scanf("%d",&n)&&n!=0){
        count++;
        memset(dp,0,sizeof(dp));
        memset(map,0,sizeof(map));
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&x,&y,&z);
			/*
				x>y>z 开始没有注意 叠块的长宽要严格 
				长大于宽 或者 宽大与长 否则可能出现本可以叠而不能的现象 出现WA
			*/
			if(x<y)swap(x,y);
			if(x<z)swap(x,z);
			if(y<z)swap(y,z);
            map[i*3].x=x,map[i*3].y=y,map[i*3].z=z;
            map[i*3+1].x=y,map[i*3+1].y=z,map[i*3+1].z=x;
            map[i*3+2].x=x,map[i*3+2].y=z,map[i*3+2].z=y;
        }
        sort(map,map+n*3,cmp);
        for(int i=0;i<n*3;i++){
            dp[i]=map[i].z;
            for(int j=0;j<i;j++){
                if(map[i].x<map[j].x&&map[i].y<map[j].y){
                    if(dp[j]+map[i].z>dp[i])dp[i]=dp[j]+map[i].z;
                }
            }
        }
        int smax=0;
        for(int i=0;i<n*3;i++){
            if(dp[i]>dp[smax])smax=i;
        }
        printf("Case %d: maximum height = %d\n",count,dp[smax]);
    }
    return 0;
}