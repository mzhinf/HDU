//#define LOCAL
#include <cstdio>
#include <cstring>
int w[21][21][21];
int work(int a,int b,int c){
	if(a<=0||b<=0||c<=0)return 1;
	if(a>20||b>20||c>20)return work(20,20,20);
	if(w[a][b][c])return w[a][b][c];
	if(a<b&&b<c){// w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
		return work(a, b, c-1) + work(a, b-1, c-1) - work(a, b-1, c);
	}
	else{//w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
		return work(a-1, b, c) + work(a-1, b-1, c) + work(a-1, b, c-1) - work(a-1, b-1, c-1);
	}
}
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    memset(w,0,sizeof(w));
    for(int i=0;i<=20;i++){
    	for(int j=0;j<=20;j++){
    		for(int k=0;k<=20;k++){
    			if(!w[i][j][k])w[i][j][k]=work(i,j,k);
    		}
    	}
    }
    int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c)){
		if(a==-1&&b==-1&&c==-1)break;
		printf("w(%d, %d, %d) = %d\n",a,b,c,work(a,b,c));
	}
    return 0;
}

