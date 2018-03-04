#include <cstdio>

int main(){
	int t;
	char s[6]="aeiou";
	char str[100];
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		for(int i=0;str[i]!='\0';i++){
			char ch=str[i];
			if(str[i]>='A'&&str[i]<='Z')ch+=32;
			for(int j=0;j<5;j++){
				if(ch==s[j]){
					ch-=32;break;
				}
			}
			printf("%c",ch);
		}
		printf("\n");
	}
	return 0;
}
