#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <iterator>
using namespace std;
const int MAX_V=1005;
const int INF=0x3f3f3f3f;

struct edge{
    int to,//�ձ�
        cap,//����
        rev;//�����
};
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

//����һ����from��to������Ϊcap�ı�
void add_edge(int from,int to,int cap){
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
}

//ͨ��bfs�����Դ������ľ�����
void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        int v=que.front(); que.pop();
        for(int i=0;i<G[v].size();i++){
            edge &e=G[v][i];
            if(e.cap>0&&level[e.to]<0){
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}

//ͨ��dfsѰ������·
int dfs(int v,int t,int f){
    if(v==t)return f;
    for(int &i=iter[v];i<G[v].size();i++){
        edge &e = G[v][i];
        if(e.cap>0&&level[v]<level[e.to]){
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

//����s��t�������
int max_flow(int s,int t){
    int flow=0;
    for(;;){
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,INF))>0){
            flow+=f;
        }
    }
}

const int MAX_N=1005;
vector< pair<int,int> > g[MAX_N];
bool map[MAX_N];

void init(int n){
    for(int i=1;i<1005;i++){
        g[i].clear();
        vector< pair<int,int> >().swap(g[i]);
        G[i].clear();
        vector<edge>().swap(G[i]);
        map[i]=false;
    }
    map[n]=true;
}

void g_bfs(int s,int e){
    vector< pair<int,int> >::iterator it;
    set<int> *que,*newq,*t,a,b;
    que=&a,newq=&b;
    bool flag=true;
    //��ʼ������
    for(it=g[s].begin();it!=g[s].end();it++){
        que->insert((*it).first);
        add_edge(s,(*it).first,(*it).second);
        if((*it).first==e)flag=false;
    }
    //��ʼbfs
    while(flag&&!que->empty()){
        //������Ԫ�ر�� �ôα������ܷ���
        while(!que->empty()){
            int ss=*que->begin(); que->erase(ss);
            map[ss]=true;
            newq->insert(ss);
        }
        t=newq,newq=que,que=t;
        //��������que �����¶���newq
        while(!que->empty()){
            int ss=*que->begin(); que->erase(ss);
            for(it=g[ss].begin();it!=g[ss].end();it++){
                if(!map[(*it).first]){//�õ�δ�����ʹ�������
                    newq->insert((*it).first);
                    if((*it).first==e)flag=false;//que�����Ѿ��ܴﵽnʱ ��һ�β��ٱ���
                    add_edge(ss,(*it).first,(*it).second);
                }
            }
        }
        t=newq,newq=que,que=t;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,u,v,w;
        scanf("%d%d",&n,&m);
        init(n);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
        g_bfs(n,1);
        printf("%d\n",max_flow(n,1));
    }
    return 0;
}

/*
5
5 5
1 2 3
2 3 1
2 4 2
3 4 1
4 5 3

5 5
1 2 1
1 3 1
2 4 1
3 4 1
4 5 3

5 5
1 2 3
2 3 1
2 4 1
3 5 1
4 5 1

3 4
1 2 2
2 3 1
2 3 1
2 3 1
*/