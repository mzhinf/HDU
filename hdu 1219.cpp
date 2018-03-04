#include <cstdio>
#include <cstring>

int main(){
	char str[100005];
	int s[30];
	while(~scanf("%[^\n]",str)){
        getchar();
		int len=strlen(str);
		memset(s,0,sizeof(s));
		for(int i=0;i<len;i++){
			if(str[i]>='a'&&str[i]<='z'){
				s[str[i]-'a']++;
			}
		}
		for(int i=0;i<26;i++){
			printf("%c:%d\n",'a'+i,s[i]);
		}
		printf("\n");
	}
	return 0;
}
