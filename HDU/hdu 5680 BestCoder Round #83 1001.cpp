/*
	BestCoder Round #83
	zxa and set
	题解:分析得求max(A)
*/
#include <cstdio>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,smax=0,temp;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			if(temp>smax)smax=temp;
		}
		printf("%d\n",smax);
	}
	return 0;
}
