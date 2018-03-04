#include <cstdio>
#include <cstring>

int f(char *str){
	int t=0;
	for(int i=0;i<strlen(str);i++){
		if(str[i]!=','&&str[i]!='-'){
			t=t*10+(str[i]-'0');
		}
	}
	if(str[0]=='-')t=-t;
	return t;
}

int main(){
    char s1[30],s2[30];
	while(~scanf("%s%s",s1,s2)){
        //printf("%s %s\n",s1,s2);
		int a=f(s1),b=f(s2);
        //printf("%d %d\n",a,b);
		printf("%d\n",a+b);
	}
	return 0;
}
