#include <cstdio>
#include <set>

using namespace std;

set<int> smap;

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		smap.clear();
		int m,v,sum=0;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d",&v);
			if(smap.count(v)){
				//清空
				smap.clear();
				smap.insert(v);
				sum++;
			} else {
				smap.insert(v);
			}
		}
		if(smap.size()>0)sum++;
		printf("%d\n",sum);
	}
	return 0;
}
