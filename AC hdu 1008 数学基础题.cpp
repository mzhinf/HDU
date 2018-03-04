//#define LOCAL
#include <cstdio>

int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n;
    while(~scanf("%d",&n)&&n!=0){
		int pos=0,t,sum=0;
    	for(int i=0;i<n;i++){
    		scanf("%d",&t);
    		if(t>pos)sum+=(t-pos)*6+5;
    		else sum+=(pos-t)*4+5;
    		pos=t;
    	}
    	printf("%d\n",sum);
    }
    return 0;
}
