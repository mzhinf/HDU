/*
	×Ö·ûÌæ»»
	*×¢Òâ:scanf("%[^\n]",str) »ñÈ¡´ø¿Õ¸ñ×Ö·û´®
*/
#include <cstdio>
#include <cstring>

char str[100];

int main(){
	while(~scanf("%[^\n]",str)){
		getchar();
		if(strcmp(str,"#")==0)break;
		for(int i=0;str[i]!='\0';i++){
			switch(str[i]){
				case ' ': printf("%s","%20");break;
				case '!': printf("%s","%21");break;
				case '$': printf("%s","%24");break;
				case '%': printf("%s","%25");break;
				case '(': printf("%s","%28");break;
				case ')': printf("%s","%29");break;
				case '*': printf("%s","%2a");break;
				default : printf("%c",str[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
