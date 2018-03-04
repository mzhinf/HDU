/*
    考虑a,b均为0的情况。
*/
#include <cstdio>

int main(){
	int m;
	int x[40];
	while(~scanf("%d",&m)&&m!=0){
		int a,b,sum;
		scanf("%d%d",&a,&b);
		sum=a+b;
		if(!sum)printf("0");
		int n=0;
		while(sum>0){
			x[n++]=sum%m;
			sum/=m;
		}
		for(int i=n-1;i>=0;i--){
			printf("%d",x[i]);
		}
		printf("\n");
	}
	return 0;
}
