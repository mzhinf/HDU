/*
	找出现次数最多的数字的次数 即所需次数
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
char s[3005][35] ;
int cmp(const void *a, const void *b){
    return strcmp((char*)a, (char*)b) ;
}
int main (){
    int n;
    while (~scanf("%d",&n)){
        for (int i=0,j;i<n;i++){
            scanf ("%s", s[i]) ;
            for(j=0;s[i][j]=='0';j++);
            strcpy(s[i],s[i]+j) ;
        }
        qsort(s,n,sizeof(s[0]),cmp);
        int smax=1,len=1;
        for(int i=1;i<n;i++){
            if(strcmp(s[i],s[i-1])==0){
				len++;
            }
            else{
				if(smax<len)smax=len;
				len=1;
			}
		}
		if(smax<len)smax=len;
        printf ("%d\n",smax) ;
    }
    return 0 ;
}
/*
//超时 估计struct排序有点伤
//#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct str{
	char s[35];
}map[3005];
bool cmp(const str& a,const str& b){
	if(strlen(a.s)>strlen(b.s))return true;
	else if(strlen(a.s)==strlen(b.s)){
		if(strcmp(a.s,b.s)>0)return true;
		else return false;
	}
	else return false;
}
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        //freopen("data.out","w",stdout);
    #endif
	int n;
	while(~scanf("%d",&n)){
		int temp;
		for(int i=0,j;i<n;i++){
			scanf("%s",map[i].s);
			for(j=0;map[i].s[j]=='0';j++);
			strcpy(map[i].s,map[i].s+j);
		}
		sort(map,map+n,cmp);
		int smax=1,len=1;
		for(int i=1;i<n;i++){
			if(strcmp(map[i-1].s,map[i].s)==0){
				len++;
			}
			else{
				if(smax<len)smax=len;
				len=1;
			}
		}
		if(smax<len)smax=len;
		printf("%d\n",smax);
	}
    return 0;
}*/
