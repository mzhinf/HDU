/*
	����С����
	����a��������p����������a,p����(������ֻ��һ����Լ��1)��
	��ôa��(p-1)�η�����p�����������1��
	
	(k*a0+18)%65==(k*(a0+65)+18)%65
	T=65
*/
#include <cstdio>

int main(){
	int k;
	while(~scanf("%d",&k)){
		int a=0;
		for(int i=1;i<=65;i++){
			if((18+k*i)%65==0){
				a=i;
				break;
			}
		}
		if(a==0) printf("no\n");
		else printf("%d\n",a);
	}
	return 0;
}