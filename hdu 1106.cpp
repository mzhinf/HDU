#include <cstdio>
#include <algorithm>
using namespace std;
char str[1005];
int a[505];
int main(){
	while(~scanf("%s",str)){
		int t=0;
		int n=0;
		bool p=false;
		for(int i=0;;i++){
            if(str[i]=='\0'){
                if(str[i-1]!='5'){
                    a[n++]=t;
                    t=0;
                }
                break;
            }
			if(str[i]=='5'){
				if(p){
					a[n++]=t;
					t=0;
					p=false;
				}
			}
			else{
				t=t*10+(str[i]-'0');
				p=true;
			}
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			printf("%d%c",a[i],(i+1==n)?'\n':' ');
		}
	}
	return 0;
}
