/*
    ����ֽ׶�������������Ѿ�ע���� ��������ĵ�����ǿ����
    
    ÿ��ȡ��ɵ������������������Ƚϣ������������
	һ�����������ȹ������Ŀ죬��ôֱ�������������ȥӮ����������
	�������������ȹ�������������ô�������������ȥ�����������
	�������������������������ٶ�һ����
	    ����������������������������Ƚϡ�
	    	����ɱȹ����죬ֱ��Ӯ��������������
	    	�����������������ȥ�����������ȡ�
    		��������������һ�����������������͹���������ȡ�

	�������Դﵽ���� �������������ڵ����������ѽ� ע��Ҫ��¼��������������ȵ���� ��ʱ��ƽ��
*/
//#define LOCAL
#include <cstdio>
#include <algorithm>
using namespace std;
int th[1005];
int kh[1005];
bool cmp(const int& a,const int& b){
	return a>b;
}
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        //freopen("data.out","w",stdout);
    #endif
	int n;
	while(~scanf("%d",&n)&&n!=0){
		int count=0,p=0;
		for(int i=0;i<n;i++){
			scanf("%d",&th[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&kh[i]);
		}
		sort(th,th+n,cmp);
		sort(kh,kh+n,cmp);
		for(int i=0,j=0,ei=n-1,ej=n-1;i<=ei&&j<=ej;){
			if(th[i]>kh[j]){//��Ӯ��Ӯ
				count++;//��Ӯ��
				i++;
				j++;
			}
			else if(th[i]==kh[j]){//���ƽ��
				if(th[ei]>kh[ej]){//��������Ƚ� ��Ӯ��Ӯ
					count++;//��Ӯ��
					ei--;
					ej--;
				}
				else{//�����������������
					if(th[ei]==kh[j])p++;//��������������� ��ƽ
					j++;
					ei--;
				}
			}
			else{//��������������
				j++;
				ei--;
			}
		}
		int sum=200*(count-(n-count-p));
		printf("%d\n",sum);
	}
    return 0;
}
