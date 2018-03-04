/*
	Ì°ÐÄ
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n,sum=0,smax=0,temp,num;
		scanf("%d",&n);
		for(int j=0;j<n;j++){
			scanf("%d",&temp);
			sum+=temp;
			if(smax<temp)smax=temp;
		}
		num=min(sum/2,(sum-smax)*2+1);
		printf("Case #%d: %d\n",i,num);
	}
	return 0;
}
