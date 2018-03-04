/*
    ¿ìËÙÃİ
*/

#include <cstdio>
const int mod=1000;
int mul(int ans,int n){
	int res=1;
	while(n>0){
		if(n&0x1)res=(res*ans)%mod;
		ans=(ans*ans)%mod;
		n>>=1;
	}
	return res;
}

int main(){
	int a,b;
	while(1){
		scanf("%d%d",&a,&b);
		if(a==0&&b==0)break;
		printf("%d\n",mul(a,b));
	}
	return 0;
}
