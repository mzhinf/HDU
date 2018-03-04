/*
    输入:5 0 0 0 0 0
    输出:0 1 1(不是0 1 5)
*/
//#define LOCAL
#include <cstdio>
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
	int t;
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		int n;
		scanf("%d",&n);
		int temp,ssum,ss,se,isum,is,ie;
		for(int i=1;i<=n;i++){
			scanf("%d",&temp);
			if(i==1){
				ssum=isum=temp;
				ss=se=is=ie=1;
			}
			else{
				if(isum>=0){
					isum+=temp;
					ie=i;
				}
				else{
					isum=temp;
					is=ie=i;
				}
			}
			if(isum>ssum){
				ssum=isum;
				ss=is;
				se=ie;
			}
		}
		printf("Case %d:\n%d %d %d\n",k,ssum,ss,se);
		if(k!=t)printf("\n");
	}
	return 0;
}
