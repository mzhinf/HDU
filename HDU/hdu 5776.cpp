/*
	Ԥ����ǰ׺�ͣ�һ����������ģm��ֵ��ͬ��˵���м�һ�����������п������m�ı�����
	���⣬���ó���ԭ�����ǿ��Եõ���һ��n���ڵ���m����һ����YES ���Ӷ� O��n��
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
		map[0]=1;//����sum%m=0����һ������ʹ����Ŀ����
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
