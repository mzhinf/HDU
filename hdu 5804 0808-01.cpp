/*
	8.8
	hdu 5804
*/
#include <cstdio>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		long long sum=0,temp;
		while(n--){
			scanf("%I64d",&temp);
			sum+=temp;
		}
		while(m--){
			scanf("%I64d",&temp);
			if(sum<temp) printf("1");
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}
