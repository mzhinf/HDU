/*
	2015 ACMICPC Asia Regional Changchun Online
	Aggregated Counting

	理论上是一个规律题
	
	upper_bound(first,last,val);//(有多种形式)
	指向[first , last)中第一个>=val的元素
	需要保证[begin , end)中元素已经有序
	http://www.cplusplus.com/reference/algorithm/upper_bound/
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int mod=1000000007;
int N,n;
long long m[500000];
long long s[500000];
long long a[500000];
void init(){
	m[1]=1;m[2]=2;N=3;
	s[1]=1;s[2]=3;
	n=3;
	for(int j=2;N<1000000001;n++){
		if(s[j]<n)j++;
		m[n]=j;
		N=s[n]=s[n-1]+j;
	}
	a[1]=1;
	for(int i=2;i<n;i++){
		a[i]=(a[i-1]+(s[i]+s[i-1]+1)*(s[i]-s[i-1])/2*i)%mod;
	}
}
int main(){
	init();
	int t=0;
	scanf("%d",&t);
	while(t--){
        long long n_;
        long long temp;
        scanf("%I64d",&n_);
        int i=upper_bound(s+1,s+n,n_)-s-1;
        //printf("%d\n",i);
        temp=(a[i]+(n_+s[i]+1)*(n_-s[i])/2*(i+1))%mod;
        printf("%I64d\n",temp);
	}
	return 0;
}
