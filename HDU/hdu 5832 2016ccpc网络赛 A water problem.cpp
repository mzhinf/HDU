#include <cstdio>
char str[10000005];
int main(){
	int n=1;
	while(~scanf("%s",&str)){
		int y1=0,y2=0;
		for(int i=0;str[i]!='\0';i++){
            int temp=str[i]-'0';
			y1=((y1*10)+temp)%73;
			y2=((y2*10)+temp)%137;
		}
		if(y1==0&&y2==0) printf("Case #%d: YES\n",n);
		else printf("Case #%d: NO\n",n);
		n++;
	}
	return 0;
}
