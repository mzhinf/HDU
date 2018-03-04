/*
    如果现阶段田忌最慢的马已经注定输 则最好消耗掉王最强的马
    
    每次取田忌的最快的马与国王最快的马比较，有三种情况。
	一，田忌最快的马比国王最快的快，那么直接拿田忌最快的马去赢国王最快的马。
	二，田忌最快的马比国王最快的慢，那么拿田忌最慢的马去输国王最快的马。
	三，田忌最快的马与国王最快的马速度一样。
	    先拿田忌最慢的马与国王最慢的马比较。
	    	若田忌比国王快，直接赢掉国王最慢的马。
	    	否则田忌最慢的马再去与国王最快的马比。
    		如果最快最慢的马都一样，用田忌最慢的马和国王最快的马比。

	互换可以达到不亏 而且在连续等于的情况下有最佳解 注意要记录最慢马和最快马相等的情况 此时记平局
*/
//#define LOCAL
#include <cstdio>
#include <algorithm>
using namespace std;
int th[1005];
int kh[1005];
bool cmp(const int& a,const int& b){
	return a>b;
}
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        //freopen("data.out","w",stdout);
    #endif
	int n;
	while(~scanf("%d",&n)&&n!=0){
		int count=0,p=0;
		for(int i=0;i<n;i++){
			scanf("%d",&th[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&kh[i]);
		}
		sort(th,th+n,cmp);
		sort(kh,kh+n,cmp);
		for(int i=0,j=0,ei=n-1,ej=n-1;i<=ei&&j<=ej;){
			if(th[i]>kh[j]){//能赢则赢
				count++;//记赢局
				i++;
				j++;
			}
			else if(th[i]==kh[j]){//如果平局
				if(th[ei]>kh[ej]){//最慢的马比较 能赢则赢
					count++;//记赢局
					ei--;
					ej--;
				}
				else{//否则拿慢马抵消快马
					if(th[ei]==kh[j])p++;//最慢马和最快马相等 记平
					j++;
					ei--;
				}
			}
			else{//输则消耗最快的马
				j++;
				ei--;
			}
		}
		int sum=200*(count-(n-count-p));
		printf("%d\n",sum);
	}
    return 0;
}
