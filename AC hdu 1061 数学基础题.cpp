/*
    暴力超时
    使用规律最佳
*/
#include <cstdio>
int tail[10][10];
int ro[10];
int main(){
	//初始化 该初始化规律较少可以手动输入
	for(int i=0,t;i<10;i++){
		tail[i][1]=i;
		t=i;
		for(int j=2;;j++){
			t=(t*i)%10;
			if(t==i){
				ro[i]=j-1;
				tail[i][0]=tail[i][j-1];
				break;
			}
			tail[i][j]=t;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int n,temp,res;
		scanf("%d",&n);
		temp=n%10;
		res=tail[temp][n%ro[temp]];
		printf("%d\n",res);
	}
	return 0;
}
/*
//暴力超时
#include <cstdio>
int main(){
	int n,t,res,rn;
	scanf("%d",&t);
	while(t--){
		res=1;
		scanf("%d",&n);
		rn=n%10;
		for(int i=0;i<n;i++){
			res=(res*rn)%10;
		}
		printf("%d\n",res);
	}
	return 0;
}
*/
