/*
	������˼·:�Ƚ�n-1λ��������һ���������ٰ���һ�����������
	��v O(n) ���� O(n) ���� O(n)
*/

#include <cstdio>
#include <cstring>

char str[10000005];
int v[15];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		int n=strlen(str);
		memset(v,0,sizeof(v));
		for(int i=0;i<n;i++) v[str[i]-'0']++;
		if(n-v[0]<=1){
			printf("Uncertain\n");
			continue;
		}
		bool flag=false;
		//�ڶ������� a
		int j,a,len=n-1;
		for(j=1;!v[j];j++);
		a=j;
		v[j]--;
		//���һλ j
		for(j=0;!v[j];j++);
		v[j]--;
		//���һλ֮�� end
		int end=(a+j)%10;
		//�ж��Ƿ��н�λ
		if(a+j>=10){
			//�н�λ flag=true;
			flag=true;
			//�жϽ�λ���Ƿ�Ϊ9
			for(j=0;!v[j];j++);
			if(j==9){
				printf("1");
				while(v[9]--){
					printf("0");
				}
				printf("%d\n",end);
				continue;
			}
		}
		//��ʼ���
		//�����λ
		for(j=0;j<10&&!v[j];j++);
		j%=10;
		v[j]--;
		if(flag)j++;
		end=j*10+end;
		if(len<=2){
			printf("%d\n",end);
			continue;
		}
        //
		for(j=9;j>0&&!v[j];j--);
		for(int i=len-2;i>0;){
			while(v[j]--){
				printf("%d",j);
				i--;
			}
			j--;
		}
		printf("%02d\n",end);
	}
	return 0;
}
