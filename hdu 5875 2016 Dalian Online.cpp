/*
	2016 ACM/ICPC Asia Regional Dalian Online
	Function
	
	预处理 ai最近的一个比ai小的数 存在next[i]中
*/
#include <cstdio>
int a[100005];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,temp,t1,t2;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i==j)b[i][j]=a[i];
                else b[i][j]=b[i][j-1]%a[j];
            }
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d%d",&t1,&t2);
			printf("%d\n",b[t1][t2]);
		}
	}
	return 0;
}
