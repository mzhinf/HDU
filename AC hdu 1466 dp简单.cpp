/*
    分析:
    将n条直线分成两部分
	a条平行线 b条自由线
	则交点分为两部分:1.平行线与自由线的交点 2.自由线自身的交点(而自由线自身的交点可以看成b条直线的交点)
	
    故:n条直线的方案=a*b+b的方案
*/
#include <cstdio>
bool visit[21][200];
int main(){
	int n;
	visit[0][0]=true;//0条自由线 则0个交点为真
	for(n=1;n<21;n++){
		for(int a=0;a<=n;a++){//a条平行线
			int b=n-a;//b条自由线
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
