/*
	http://acm.hdu.edu.cn/showproblem.php?pid=1027
	˼·:
	1-nȫ���еĵ�m��
	ʵ��:
	����next_permutation()ֱ���ҵ���m��
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
		//һ�е����һ�������ǿո� ����PE
		printf("%d",p[0]);
		for(i=1;i<n;i++)printf(" %d",p[i]);
		printf("\n");
	}
	return 0;
}
