/*


*/
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll t[305][305],e=-1;
ll tmax[305];
ll key[305];
ll val[305];

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

void init(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			t[i][j]=e;
		}
		tmax[i]=e;
	}
}

int main(){
	freopen("in.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		init(n);
		for(int i=0;i<n;i++){
			scanf("%I64d",&key[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%I64d",&val[i]);
		}
		
		for(int i=1;i<n;i++){
            if(gcd( key[i], key[i-1]) != 1){// (i-1,i) 成对
				t[i-1][i]=val[i]+val[i-1];
				for(int j=i-3;j>=0;j-=2){
					if(t[j][i-2]!=e){
						t[j][i]=max(t[j][i],t[j][i-2]+t[i-1][i]);
					}
				}
			}
			for(int j=i-2;j>0;j-=2){// (0--i-2,i) 成对
				if( t[j][i-1] != e && gcd( key[i], key[j-1]) != 1){
					t[j-1][i]=t[j][i-1]+val[i]+val[j-1];
					for(int k=j-3;k>=0;k-=2){
						if(t[k][j-2]!=e){
							t[k][i]=t[k][j-2]+t[j-1][i];
						}
					}
				}
			}
			tmax[i]=max(tmax[i],tmax[i-1]);
			for(int j=i-1;;j--){
				tmax[i]=max(tmax[i],t[j][i]);
				if(j==0)break;
				if(t[j][i]!=e&&tmax[j-1]!=e){
					tmax[i]=max(tmax[i],tmax[j-1]+t[j][i]);
				}
			}
		}
		if(tmax[n-1]!=e) printf("%I64d\n",tmax[n-1]);
		else printf("0\n");
	}
	return 0;
}

