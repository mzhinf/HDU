#include <cstdio>
#include <cstring>
int a[30];
void init(){
	int n=3;
	a[0]=2,a[1]=3,a[2]=5;
	for(int i=6,j;n<26;i++){
		for(j=2;j*j<i;j++){
			if(i%j==0)break;
		}
		if(j*j>i){
            a[n++]=i;
		}
	}
}
int f(int x[]){
	char str[200];
	int x1[30];
	int len,t=0,n=0;
	scanf("%s",str);
	len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]==','){
			x1[n++]=t;
			t=0;
		}
		else{
			t=t*10+(str[i]-'0');
		}
	}
	x1[n++]=t;
	for(int i=0;i<n;i++)x[i]=x1[n-1-i];
	return n;
}

int main(){
	init();
	//for(int i=0;i<26;i++)printf("%d\n",a[i]);
	while(1){
		int b1,b2,ba;
		int a1[30],a2[30],b[30];
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(b,0,sizeof(b));
		b1=f(a1);
		b2=f(a2);
		if(b1==1&&b2==1&&a1[0]==0&&a2[0]==0)break;
		
		//for(int i=0;i<b1;i++)printf("%d\n",a1[i]);
		//for(int i=0;i<b2;i++)printf("%d\n",a2[i]);
		if(b1>b2)ba=b1;
		else ba=b2;
		
		
		for(int i=0;i<ba;i++){
			b[i]+=a1[i]+a2[i];
			if(b[i]>=a[i]){
				b[i+1]++;
				b[i]%=a[i];
			}
		}
		if(b[ba]>0)ba++;
		
		for(int i=ba-1;i>=0;i--){
			printf("%d%c",b[i],(i-1==-1)?'\n':',');
		}
	}
	return 0;
}