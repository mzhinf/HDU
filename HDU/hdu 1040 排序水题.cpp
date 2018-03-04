/*
	排序
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int a[1005];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			printf("%d%c",a[i],i!=n-1?' ':'\n');
		}
	}
	return 0;
}
