/*
	½øÖÆ×ª»»
*/
#include <cstdio>

int sumjz(int jz,int n){
	int num=0;
	while(n){
		num+=n%jz;
		n/=jz;
	}
	return num;
}

int main(){
	int a,b,c;
	for(int i=2992;i<10000;i++){
		a=sumjz(10,i);
		b=sumjz(12,i);
		c=sumjz(16,i);
		if(a==b&&b==c)printf("%d\n",i);
	}
	return 0;
}