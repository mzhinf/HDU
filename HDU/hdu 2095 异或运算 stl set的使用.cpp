/*
	���:����ʹ��ƽ����ʱ�临�Ӷ� O(n*log(n))
	
	Exe.Time	Exe.Memory	Code Len.	Language	
	733MS		1456K		419B		G++
	998MS		1740K		419B		C++
	
	*��������� Ч������
	a^a=0 c^0=c ���ұ���������ֻ��һ����������(����������,��Ϊ1)
	������������򼴿�
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
			if(sall.count(temp)){//���ֹ�
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