/*
	����
	����һ�ٸ��㣬�Ҹ�����Щ��Ϊ���ĵ���С��Բ��
	ʹ�����Բǡ�ð�����n���㣬�������Բ�ı߽��ϲ�û�е�
	
	���
	����ö�پ���
	�������
	ѡ���n��ľ�������
*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double eps=1e-8;
double x[105],y[105];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		vector<double> d[105];
		int n,m;
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++){
			scanf("%lf%lf",&x[i],&y[i]);
		}
		for(int i=0;i<m;i++){
			for(int j=i+1;j<m;j++){//i j��ʵ�ʾ���
				double tx=x[i]-x[j];
				double ty=y[i]-y[j];
				double temp=sqrt(tx*tx+ty*ty);
				d[i].push_back(temp);
				d[j].push_back(temp);
			}
			d[i].push_back(0);
		}
		int r=1e9;
		for(int i=0;i<m;i++){
			sort(d[i].begin(),d[i].end());
			int p=(int)ceil(d[i][n-1]+eps);//��d[i][n-1]Ϊ���� p=d[i][n-1]+1
			if(n==m||d[i][n]-p>eps){
				r=min(r,p);
			}
		}
		if(r==1e9)printf("-1\n");
		else printf("%d\n",r);
	}
	return 0;
}