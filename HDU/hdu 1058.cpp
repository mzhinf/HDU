#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#define LL long long
using namespace std;
char af[15][4]={"th","st","nd","rd","th","th","th","th","th","th"};
int a[5]={2,3,5,7};
LL map[6000];
void init(){
	priority_queue<LL, vector<LL>, greater<LL> > pq;
	set<LL> s;
	pq.push(1);
	s.insert(1);
	for(int i=1;i<5850;i++){
		LL x=pq.top(); pq.pop();
		map[i]=x;
		for(int j=0;j<4;j++){
			LL x1=x*a[j];
			if(!s.count(x1)){
				s.insert(x1);
				pq.push(x1);
			}
		}
	}
}
int main(){
	init();
	int n;
	while(~scanf("%d",&n)&&n!=0){
		if((n%100/10)==1)
			printf("The %dth humble number is %I64d.\n",n,map[n]);
		else
			printf("The %Id%s humble number is %I64d.\n",n,af[n%10],map[n]);
	}
	return 0;
}
