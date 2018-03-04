/*
3
9
8 4 3 3 3 3 3 2 1
8 8 8 8 8 8 9 9 9
9
8 4 4 4 4 4 3 2 1
8 8 9 9 9 9 9 9 9
9
8 1 1 1 1 1 1 1 1
8 8 9 9 9 9 9 9 9

6
6
720
*/
#include <cstdio>

int B[100005];
int C[100005];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&B[i]);
		for(int i=1;i<=n;i++)scanf("%d",&C[i]);
		if(B[1]!=C[1]){//因为A[1]=B[1]=C[1] 所以B[1]!=C[1] 无解
			printf("0\n");
			continue;
		}
		int b=B[1],c=C[1],len=0;
		long long sum=1;
		for(int i=2;i<=n;i++){
			if(B[i]!=b&&C[i]!=c||B[i]>b||C[i]<c){
				sum=0;
				break;
			}
			else if(B[i]<b){
				len+=b-B[i]-1;//扩充可以使用的A[i]
				b=B[i];
			}
			else if(C[i]>c){
				len+=C[i]-c-1;
				c=C[i];
			}
			else{
				if(len==0){//A[i]没有值可以使用
					sum=0;
					break;
				}
				sum=(sum*len)%998244353;
				//printf("%d %d %d\n",b,c,sum);
				len--;
			}
		}
		printf("%I64d\n",sum);
	}
	return 0;
}
