#include <cstdio>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		if(n%2==0)printf("Bad\n");
		else printf("Balanced\n");
	}
	return 0;
}