/*
	BestCoder Round #89
	Fxx and string
    题解:
    枚举y 与 公比q 检查是否符合情况的
    
    *注意等比数列的公比小于1的情况
*/
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char str[10005];
vector<int> vy;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		int n=strlen(str),num=0;
		vy.clear();
		for(int i=0;i<n;i++){
			if(str[i]=='y') vy.push_back(i+1);
		}
		vector<int>::iterator iy;
		for(iy=vy.begin();iy!=vy.end();iy++){
			for(int i=2;;i++){//q>1
				if( (*iy)*i*i <= n ){
					if( str[(*iy)*i-1]=='r' && str[(*iy)*i*i-1]=='x' ) num++;
				}
				else break;
			}
			for(int i=2;(*iy)>=(i*i);i++){//q<1
				if( (*iy)%(i*i) == 0 ){
					if( str[(*iy)/i-1]=='r' && str[(*iy)/(i*i)-1]=='x' ) num++;
				}
			}
		}
		printf("%d\n",num);
	}
	return 0;
}
