/*
	8.8
	hdu 5805


*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100005];
int c[100005];
int s[100005];
int e[100005];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		//预处理
		c[0]=0;
		for(int i=1;i<n;i++){
			c[i]=abs(a[i]-a[i-1]);
		}
		//以i结尾的最大
		e[0]=0;
		for(int i=1;i<n;i++){
			e[i]=max(c[i],e[i-1]);
		}
		//以i起始的最大
		s[n-1]=0;
		for(int i=n-2;i>-1;i--){
			s[i]=max(c[i+1],s[i+1]);//以i起始的 记录在i+1
		}
		//期望
		long long sum=0;
		int temp;
		for(int i=1;i<n-1;i++){
			temp=abs(a[i+1]-a[i-1]);
			temp=max(temp,e[i-1]);
			temp=max(temp,s[i+1]);
			sum+=temp;
		}
		//例外i=0
		sum+=s[1];
		sum+=e[n-2];
		printf("%I64d\n",sum);
	}
	return 0;
}
