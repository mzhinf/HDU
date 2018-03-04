/*
    分数问题
    
    sum=n/n + n/(n-1) + n/(n-2) + ... + n/1;
*/
#include <cstdio>
typedef long long ll;
struct F{
	ll a,b,c;
	F(){}
	F(ll a1, ll b1, ll c1){
		ll t=gcd(a1,b1);
		a=a1/t;
		b=b1/t;
		c=c1;
		if(a>b){
			c+=a/b;
			a%=b;
			if(a==0)b=1;
		}
	}
	F operator + (F f){
		return F(a*f.b+b*f.a, b*f.b, c+f.c);
	}
	F operator - (F f){
		return F(a*f.b-b*f.a, b*f.b, c+f.c);
	}
	int gcd(ll a,ll b){
		if(b==0) return a;
		return gcd(b,a%b);
	}
};

int l(ll a){
	int la=0;
	while(a>0){
		a/=10;
		la++;
	}
	return la;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		F sum(0,1,1);
		for(int i=1;i<n;i++){
			sum = sum + F(n,n-i,0);
			//printf("%I64d %I64d %I64d\n",sum.a,sum.b,sum.c);
		}
		if(sum.a==0)printf("%I64d\n",sum.c);
		else{
			int la=l(sum.a),lb=l(sum.b),lc=l(sum.c),ld;
			if(la>lb) ld=la;
			else ld=lb;
			for(int i=0;i<=lc;i++)printf(" ");
			printf("%I64d\n",sum.a);
			printf("%I64d ",sum.c);
			for(int i=0;i<ld;i++)printf("-");
			printf("\n");
			for(int i=0;i<=lc;i++)printf(" ");
			printf("%I64d\n",sum.b);
		}
	}
	return 0;
}
