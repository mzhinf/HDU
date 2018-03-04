/*
	n,m互质即可遍历所有数据
*/
#include <cstdio>

int gcd(int a,int b){
	return (a%b==0)?b:gcd(b,a%b);
}

int main(){
	int n=0,m=0;
	while(1){
		scanf("%d%d",&n,&m);
		if(n==-1&&m==-1)break;
		if(gcd(n,m)==1) printf("YES\n");
		else printf("POOR Haha\n");
	}
	return 0;
}