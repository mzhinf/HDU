#include <cstdio>
#include <cstring>
int d[100005];
int v[100005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,a,b;
        memset(d,0,sizeof(d));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&v[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            d[a]++;d[b]++;
        }
        int dnum=0,res=0;
        for(int i=1;i<=n;i++){
            if(d[i]%2!=0)dnum++;
            int temp=d[i];
            while(temp>0){
                temp-=2;
                res^=v[i];
            }
        }
        if(dnum==2) printf("%d\n",res);
        else if(dnum==0){
            int smax=res;
            for(int i=1;i<=n;i++){
                if(d[i]>0){
                    if(smax<(res^v[i]))smax=res^v[i];
                }
            }
            printf("%d\n",smax);
        }
        else printf("Impossible\n");
    }
    return 0;
}