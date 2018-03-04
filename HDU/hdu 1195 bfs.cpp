/*
	bfs+记忆访问状态
	9*9*9*9种状态
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct P{
    int p[4];
	P(){}
	P(const P&a){
		for(int i=0;i<4;i++)p[i]=a.p[i];
	}
};
P s,e,t,temp;
queue<P> qq,sqq;
queue<P> *q=&qq,*sq=&sqq;
int step;
int map[10005];
int di[2]={0,7};

bool isEqual(const P&a,const P&b){
	for(int i=0;i<4;i++) if(a.p[i]!=b.p[i]) return false;
	return true;
}

void kz(P a){
	int st;
	for(int i=0;i<4;i++){
		for(int j=0;j<2;j++){
			t=a;
			t.p[i]=(t.p[i]+di[j])%9+1;
			st=t.p[0]*1000+t.p[1]*100+t.p[2]*10+t.p[3];
			if(!map[st]){
				map[st]=step;
				sq->push(t);
			}
		}
	}
	for(int i=0;i<3;i++){
		t=a;
		swap(t.p[i],t.p[i+1]);
		st=t.p[0]*1000+t.p[1]*100+t.p[2]*10+t.p[3];
		if(!map[st]){
			map[st]=step;
			sq->push(t);
		}
	}
}

int bfs(){
	step=1;
	while(1){
		while(!q->empty()){
			temp=q->front();
			if(isEqual(temp,e)){
                while(!q->empty()){temp=q->front();q->pop();}
				while(!sq->empty()){temp=sq->front();sq->pop();}
				return step;
			}
			kz(temp);
			q->pop();
		}
		swap(q,sq);
		step++;
	}
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
    	memset(map,0,sizeof(map));
        int ss,se;
		scanf("%d%d",&ss,&se);
		map[ss]=-1;
		for(int i=3;i>=0;i--){
			s.p[i]=ss%10;ss/=10;
			e.p[i]=se%10;se/=10;
		}
		q->push(s);
		printf("%d\n",bfs()-1);
    }
    return 0;
}