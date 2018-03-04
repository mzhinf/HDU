/*
	题意:解决5题100分 解决0题50分
	解决其他题目x人 则前x/2加5分
*/
#include <cstdio>
#include <algorithm>
using namespace std;

struct solve{
	int v;
	int t;
	int b;
};
solve x[105];
int output[105];

bool cmp(const solve &a, const solve &b){
	if(a.v>b.v)return true;
	else if(a.v==b.v){
		if(a.t<b.t)return true;
		else return false;
	}
	else return false;
}

int main(){
	int n,num[5];
	char str[10];
	while(~scanf("%d",&n)&&n!=-1){
		num[1]=num[2]=num[3]=num[4]=0;
		for(int i=0;i<n;i++){
            x[i].b=i;
			scanf("%d",&x[i].v);
			switch(x[i].v){
				case 0:output[i]=50;break;
				case 5:output[i]=100;break;
				case 1:num[1]++;break;
				case 2:num[2]++;break;
				case 3:num[3]++;break;
				case 4:num[4]++;break;
			}
			scanf("%s",str);
			x[i].t=((str[0]-'0')*10+(str[1]-'0'))*60*60+
			((str[3]-'0')*10+(str[4]-'0'))*60+
			(str[6]-'0')*10+(str[7]-'0');
		}
		sort(x,x+n,cmp);
		for(int i=1;i<5;i++)num[i]/=2;
		for(int k=5,i=0;k>=0&&i<n;k--){
			for(;k==x[i].v&&i<n;i++){
				if(k==5||k==0)continue;
				if(num[k]){
				    output[x[i].b]=100-(5-k)*10+5;
					num[k]--;
				}
				else{
					output[x[i].b]=100-(5-k)*10;
				}
			}
		}
		for(int i=0;i<n;i++)printf("%d\n",output[i]);
		printf("\n");
	}
	return 0;
}
