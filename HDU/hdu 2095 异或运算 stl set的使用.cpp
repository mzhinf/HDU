/*
	题解:本人使用平衡树时间复杂度 O(n*log(n))
	
	Exe.Time	Exe.Memory	Code Len.	Language	
	733MS		1456K		419B		G++
	998MS		1740K		419B		C++
	
	*利用异或处理 效果更佳
	a^a=0 c^0=c 而且本题中有且只有一个整数奇数(即所需礼物,且为1)
	将所有数字异或即可
*/
#include <cstdio>
#include <set>

using namespace std;
set<int> sonly;
set<int> sall;
int main(){
	int n,temp;
	while(~scanf("%d",&n)&&n!=0){
		sonly.clear();
		sall.clear();
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			if(sall.count(temp)){//出现过
				sonly.erase(temp);
			}
			else{
				sall.insert(temp);
				sonly.insert(temp);
			}
		}
		printf("%d\n",*sonly.begin());
	}
	return 0;
}