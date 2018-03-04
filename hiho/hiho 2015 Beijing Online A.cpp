/*
	题意
	给你一百个点，找个以这些点为中心的最小的圆，
	使得这个圆恰好包含了n个点，而且这个圆的边界上并没有点
	
	题解
	暴力枚举距离
	排序距离
	选择第n大的距离特判
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
			for(int j=i+1;j<m;j++){//i j的实际距离
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
			int p=(int)ceil(d[i][n-1]+eps);//若d[i][n-1]为整数 p=d[i][n-1]+1
			if(n==m||d[i][n]-p>eps){
				r=min(r,p);
			}
		}
		if(r==1e9)printf("-1\n");
		else printf("%d\n",r);
	}
	return 0;
}