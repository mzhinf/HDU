#include <cstdio>
char str[10005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		int n;
		char c;
		for(int i=0;str[i]!='\0';i++){
			if(i==0){
				n=1;c=str[0];
			}
			else if(c!=str[i]){
				if(n!=1)printf("%d",n);
				printf("%c",c);
				n=1;c=str[i];
			}
			else n++;
		}
		if(n!=1)printf("%d",n);
		printf("%c\n",c);
	}
	return 0;
}