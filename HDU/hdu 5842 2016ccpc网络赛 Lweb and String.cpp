/*
    给出一个字符串，确定一组字符到自然数的一一映射
*/

#include <cstdio>
#include <cstring>
char str[100005];
bool m[30];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",&str);
		memset(m,0,sizeof(m));
		for(int j=0;str[j]!='\0';j++){
			m[str[j]-'a']=true;
		}
		int sum=0;
		for(int j=0;j<26;j++){
			if(m[j])sum++;
		}
		printf("Case #%d: %d\n",i,sum);
	}
	return 0;
}

