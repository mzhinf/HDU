#include <cstdio>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		double a,b=0.25,c=0.25;
		int num=4;
		scanf("%lf",&a);
		if(a>0.5)a=1-a;
		while(a>b&&num<2000){
            c*=0.5;
			b=b+c;
			num+=4;
		}
		if(a==b||a==0.5||a==0)num=-1;
		printf("%d\n",num);
	}
	return 0;
}
