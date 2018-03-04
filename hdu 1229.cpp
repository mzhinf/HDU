#include <cstdio>

int main(){
	int a,b,k;
	while(~scanf("%d%d%d",&a,&b,&k)){
		if(a==0&&b==0)break;
		int ta=a,tb=b,i;
		for(i=0;i<k;i++){
			if(ta%10!=tb%10)break;
			ta/=10;
			tb/=10;
		}
		if(i==k) printf("-1\n");
		else printf("%d\n",a+b);
	}
	return 0;
}
