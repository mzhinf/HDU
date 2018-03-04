/*
	http://acm.hdu.edu.cn/showproblem.php?pid=1027
	思路:
	1-n全排列的第m个
	实现:
	利用next_permutation()直接找到第m个
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define PSIZE 1010

int main(){
	int p[PSIZE];
	int n,m,i;
	while(~scanf("%d%d",&n,&m)){
		for(i=0;i<n;i++)p[i]=i+1;
		for(i=1;i<m;i++)next_permutation(p,p+n);
		//一行的最后一个不能是空格 否则PE
		printf("%d",p[0]);
		for(i=1;i<n;i++)printf(" %d",p[i]);
		printf("\n");
	}
	return 0;
}
