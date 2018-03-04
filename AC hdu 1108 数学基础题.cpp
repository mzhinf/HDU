#include <cstdio>
#include <algorithm>
using namespace std;
/*
//µÝ¹é 15MS
int gcd(int a,int b){
	return (a%b==0)?b:gcd(b,a%b);
}
*/
//·ÇµÝ¹é 0MS
int gcd(int a,int b){
	int temp;
	while(b!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		if(a<b)swap(a,b);
		printf("%d\n",lcm(a,b));
	}
	return 0;
}
