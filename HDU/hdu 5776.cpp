/*
	预处理前缀和，一旦有两个数模m的值相同，说明中间一部分连续子列可以组成m的倍数。
	另外，利用抽屉原理，我们可以得到，一旦n大于等于m，答案一定是YES 复杂度 O（n）
*/
#include <cstdio>
#include <cstring>
int map[5005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		int sum=0;
		bool flag=false;
		memset(map,0,sizeof(map));
		map[0]=1;//其中sum%m=0存在一个即可使得题目成立
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
            int temp;
			scanf("%d",&temp);
            sum+=temp;
            if(map[sum%m]++)flag=true;
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
