/*
	���㹲��+����ö��
*/
//468MS	1716K
//#define LOCAL
#include <cstdio>
int x[705],y[705];
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n;
    while(~scanf("%d",&n)){
    	//����
        for(int i=0;i<n;i++){
        	scanf("%d%d",&x[i],&y[i]);
        }
        //����
        int smax=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){//ÿһ��i,j����һ�ַ���
				int ans=2;
				int a=x[j]-x[i];
				int b=y[j]-y[i];
				for(int k=j+1;k<n;k++){
					if(a*(y[k]-y[j])-b*(x[k]-x[j])==0)ans++;
				}
				if(smax<ans)smax=ans;
			}
		}
		printf("%d\n",smax);
    }
    return 0;
}
