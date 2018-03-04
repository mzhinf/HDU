#include <cstdio>
#include <cstring>
char J[10][6]={
	"zero","one","two","three","four","five","six","seven","eight","nine"
};
int judge(char *s){
	for(int i=0;i<10;i++){
		if(strcmp(s,J[i])==0)return i;
	}
	return -1;
}

int main(){
    char str[10];
	while(1){
		int a=0,b=0;
		while(~scanf("%s",str)&&str[0]!='+'){
			a=a*10+judge(str);
		}
		while(~scanf("%s",str)&&str[0]!='='){
			b=b*10+judge(str);
		}
		if(a==0&&b==0) break;
		else printf("%d\n",a+b);
	}
	return 0;
}
