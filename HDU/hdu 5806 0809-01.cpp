/*
	8.8
	hdu 5806

*/
#include <cstdio>
#include <cmath>
int a[200005];
int b[200005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		//处理大于数组
		b[0]=0;
		for(int i=1;i<=n;i++){
			b[i]=b[i-1];
			if(a[i]>=m)b[i]++;
		}
		//枚举端点
		long long sum=0;
		int j=k;
		for(int i=1;i<=n;i++){
			for(;j<=n;j++){
				if(b[j]-b[i-1]>=k){
                    sum+=(n-j+1);break;
                    //printf("%d %d\n",i,j);
				}
			}
		}
		printf("%I64d\n",sum);
	}
	return 0;
}
