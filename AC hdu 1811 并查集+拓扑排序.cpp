/*
	1 0
	OK
	ע��N,M�ķ�Χ ��������N,M(0<=N<=10000,0<=M<=20000) N��M���ܵ���0
*/
//#define LOCAL
#include <cstdio>
#include <cstring>
#include <malloc.h>
#include <algorithm>
#include <queue>
using namespace std;
queue<int> st;
//�ڽӱ�
struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
};
struct VNode {
	int csnum;
	ArcNode firstarc;
}v[10005];
bool vmap[10005];//��ʾi�Ƿ񱻷���
bool s[10005];//��ʾi�Ƿ񱻼�¼(�������Ƿ����)

//��¼��������
int a[20005],b[20005];
char c[20005][2];

//���鼯
int id[10005];
int ucount;

//�ж��������
bool cflag=false,uflag=false;


int find(int p){//Ѱ��p�ĸ��ڵ� O(logN)
	int r=id[p];
	while (r != id[r])r=id[r];//ѭ���ҵ����ڵ�
	int f;//���ڵ�
	while (p != r){
		f=id[p];//��ȡ���ڵ�
		id[p]=r;//�޸ĸýڵ�
        p=f;//ѭ���޸ĸ��ڵ�
	}
	return r;
}
void merge(int p, int q){//��ͨp q (�ϲ�p q�ļ���) O(1)
	int i = find(p);//��ȡp���ڵ�
	int j = find(q);//��ȡq���ڵ�
	if (i == j)return ;
	id[j] = i;
	ucount--;//p q�ϲ� ����һ������
}
void first(int n){//��ʼ������
	ucount = n;
	for (int i = 0; i < n; i++){ id[i] = i; v[i].firstarc.nextarc=NULL; v[i].csnum=0;}//��ʼ��id
	memset(vmap,0,sizeof(vmap));
	memset(s,0,sizeof(s));
	cflag=false,uflag=false;
	while(st.size())st.pop();
}
//visit
void visit(int i){
	v[i].csnum--;
	ArcNode *p=v[i].firstarc.nextarc;
	for(int i;p!=NULL;p=p->nextarc){
		i=p->adjvex;
		i==find(i);
		v[i].csnum--;
		if(v[i].csnum!=0||vmap[i])continue;
		else st.push(i);
		vmap[i]=true;
	}
}
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        //freopen("data.out","w",stdout);
    #endif
    int n,m;
	ArcNode *p;//ÿ�δ����Ľ��
    while(~scanf("%d%d",&n,&m)){//n 0--n-1
    	if(n==0){
    		printf("OK\n");continue;
    	}
    	else if(n==1&&m==0){
    		printf("OK\n");continue;
    	}
    	first(n);
    	//������Ϣ �ϲ�����
		for(int i=0;i<m;i++){
			scanf("%d%s%d",&a[i],c[i],&b[i]);
			s[a[i]]=1;
			s[b[i]]=1;
			if(c[i][0]=='='){
				merge(a[i],b[i]);continue;
			}
			else if(c[i][0]=='<')swap(a[i],b[i]);
		}
		//����·����Ϣ
		for(int i=0;i<m;i++){
			if(c[i][0]!='='){//a[i] > b[i]
				p=(ArcNode *) malloc (sizeof(ArcNode));
				p->nextarc=NULL;
				int ta=find(a[i]);//ta>tb
				int tb=find(b[i]);
				p->adjvex=tb;
				p->nextarc=v[ta].firstarc.nextarc;
				v[ta].firstarc.nextarc=p;
				v[tb].csnum++;//ta->tb tbǰ����һ
			}
		}
		//��������
		for(int i=0;i<n;i++){
			int t=find(i);
			if(v[t].csnum!=0||vmap[t])continue;
			else st.push(t);
			vmap[t]=true;
		}
		while(st.size()){
			if(st.size()>1)uflag=true;
			visit(st.front());
			st.pop();
		}
		//�ж����
		for(int k=0;k<n;k++){
			if(!s[k]){//����δ¼��
				uflag=true;
			}
			int t=find(k);
			if(!vmap[t]){//���ڻ�
				cflag=true;
				break;
			}
		}
		if(cflag)
			printf("CONFLICT\n");
		else if(uflag)
			printf("UNCERTAIN\n");
		else
			printf("OK\n");
    }
    return 0;
}
