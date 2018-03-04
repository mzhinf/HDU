//AC Exe.Time:951MS Exe.Memory:2692K
//#define LOCAL
#include <cstdio>
#include <cstring>
bool a[1000005];
inline bool scan_d(int &num){//加速外挂 感觉还慢了
	char in;
	bool IsN=false;
	in=getchar();
	if(in==EOF)return false;
	while(in!='-'&&(in<'0'||in>'9'))in=getchar();
	if(in=='-'){
		IsN=true;num=0;
	}
	else num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
		num*=10,num+=in-'0';
	}
	if(IsN) num=-num;
	return true;
}
int main(){
	#ifdef LOCAL
		freopen("data.in","r",stdin);
		freopen("data.out","w",stdout);
	#endif
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(a,0,sizeof(a));
		int temp;
		for(int i=0;i<n;i++){
			scan_d(temp);
			temp+=500000;
			a[temp]=true;
		}
		for(int i=1000000,j=0;i>-1;i--){
			if(a[i]){
				j++;
				if(j!=1)printf(" ");
				printf("%d",i-500000);
			}
			if(j==m)break;
		}
		printf("\n");
	}
	return 0;
}





/*
//AC Exe.Time:592MS Exe.Memory:2696K
#define LOCAL
#include <cstdio>
#include <cstring>
bool a[1000005];
int main(){
	#ifdef LOCAL
		freopen("data.in","r",stdin);
		freopen("data.out","w",stdout);
	#endif
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(a,0,sizeof(a));
		int temp;
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			temp+=500000;
			a[temp]=true;
		}
		for(int i=1000000,j=0;i>-1;i--){
			if(a[i]){
				j++;
				if(j!=1)printf(" ");
				printf("%d",i-500000);
			}
			if(j==m)break;
		}
		printf("\n");
	}
	return 0;
}
*/





/*
//AC Exe.Time:858MS Exe.Memory:3680K
//使用STL sort()
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000005];
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		sort(a,a+n);
		printf("%d",a[n-1]);
		for(int i=n-2;i>=n-m;i--)printf(" %d",a[i]);
		printf("\n");
	}
	return 0;
}
*/
