#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int a[100005];
int num[100005];
int b[100005];
int c[100005];
int n;
set<int> ss;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

void solve(int x){
	x=n/x;
	memset(b+1,0,sizeof(int)*n);
	memset(c+1,0,sizeof(int)*n);
	bool flag=false;
	set<int> s;
	int num=n/x;
	for(int i=0;i<x;i++){
		b[a[i]]++;
		c[a[i]]++;
		s.insert(a[i]);
	}
	for(int i=2;i<=num;i++){
		for(int j=(i-1)*x;j<i*x;j++) c[a[j]]++;
		set<int>::iterator it;
		for(it=s.begin();it!=s.end();it++){
			if(b[*it]*i!=c[*it]){
				flag=true;break;
			}
		}
		if(flag)break;
	}
	if(!flag)ss.insert(x);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(num+1,0,sizeof(int)*n);
		ss.clear();
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			num[a[i]]++;
		}
		int temp=n;
		for(int i=1;i<n;i++){
			if(num[i]==0)continue;
			else{
				temp=gcd(temp,num[i]);
				if(temp==1)break;
			}
		}
		
		if(temp==n){
			for(int i=1;i<temp;i++){
				if(temp%i==0){
					ss.insert(i);
				}
			}
		}
		else{
			for(int i=1;i<temp;i++){
				if(temp%i==0){
					solve(temp/i);
				}
			}
		}

		ss.insert(n);
		set<int>::iterator it;
		for(it=ss.begin();it!=ss.end();it++){
			if(it!=ss.begin())printf(" ");
			printf("%d",*it);
		}
		printf("\n");
	}
	return 0;
}