#include <cstdio>
#include <cstring>
int visit[8][8];//visit[i][j] 表示 map[n-1]=i map[n-2]=j 的情况是否出现过
int map[70];//map[i] 表示第i次出现的值
int r;//代表轮回次数
int t;

int main(){
	int A,B,n;
	while(~scanf("%d%d%d",&A,&B,&n)){
		if(A==0&&B==0&&n==0)break;
		
		memset(visit,0,sizeof(visit));
		memset(map,0,sizeof(map));

		map[1]=map[2]=1;
		visit[1][1]=2;
		for(int i=3;;i++){
			map[i]=(A*map[i-1]+B*map[i-2])%7;
			//printf("%d\n",map[i]);
			if(visit[map[i]][map[i-1]]){
				r=i-visit[map[i]][map[i-1]];
				t=visit[map[i]][map[i-1]];
				break;
			}
			visit[map[i]][map[i-1]]=i;
		}
		//printf("%d %d\n",r,t);
		if(n<=t)
			printf("%d\n",map[n]);
		else
			printf("%d\n",map[(n-t)%r+t]);
		/*
		map[1]=map[2]=1;
		for(int i=3;i<=n;i++){
			map[i]=(A*map[i-1]+B*map[i-2])%7;
		}
		printf("%d\n",map[n]);
		*/
	}
	return 0;
}
