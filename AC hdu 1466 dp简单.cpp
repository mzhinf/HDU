/*
    ����:
    ��n��ֱ�߷ֳ�������
	a��ƽ���� b��������
	�򽻵��Ϊ������:1.ƽ�����������ߵĽ��� 2.����������Ľ���(������������Ľ�����Կ���b��ֱ�ߵĽ���)
	
    ��:n��ֱ�ߵķ���=a*b+b�ķ���
*/
#include <cstdio>
bool visit[21][200];
int main(){
	int n;
	visit[0][0]=true;//0�������� ��0������Ϊ��
	for(n=1;n<21;n++){
		for(int a=0;a<=n;a++){//a��ƽ����
			int b=n-a;//b��������
			for(int i=b*(b-1)/2;i>=0;i--){
				if(visit[b][i])visit[n][a*b+i]=true;
			}
		}
	}
	while(~scanf("%d",&n)){
		printf("0");
		for(int i=1;i<200;i++){
			if(visit[n][i])printf(" %d",i);
		}
		printf("\n");
	}
	return 0;
}
