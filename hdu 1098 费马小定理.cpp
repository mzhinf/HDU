/*
	费马小定理
	假如a是整数，p是质数，且a,p互质(即两者只有一个公约数1)，
	那么a的(p-1)次方除以p的余数恒等于1。
	
	(k*a0+18)%65==(k*(a0+65)+18)%65
	T=65
*/
#include <cstdio>

int main(){
	int k;
	while(~scanf("%d",&k)){
		int a=0;
		for(int i=1;i<=65;i++){
			if((18+k*i)%65==0){
				a=i;
				break;
			}
		}
		if(a==0) printf("no\n");
		else printf("%d\n",a);
	}
	return 0;
}