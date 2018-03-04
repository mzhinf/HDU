#include <cstdio>
#include <cstring>

int main(){
	char str[1005];
	while(~scanf("%[^\n]",str)){
		getchar();
		int len=strlen(str);
		for(int i=0;i<len;i++){
			if(str[i]>='A'&&str[i]<='Z')str[i]+=32;
		}
		printf("%s\n",str);
	}
	return 0;
}
