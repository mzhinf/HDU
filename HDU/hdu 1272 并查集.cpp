//#define LOCAL
#include <cstdio>
#include <set>
using namespace std;

//Union-Find ���鼯 start----------
int id[100005],h[100005]; //id[i]��ʾi�ĸ��ڵ� h[i]��ʾi�ĸ߶�
int ucount; //��ͨ������
bool flag;
set<int> map;

void first(int n){//��ʼ������
	ucount=0;
	flag = false;
	for (int i = 1; i <= n; i++){ id[i] = i;h[i] = 1; }//��ʼ��id �� ����h
	map.clear();
}

int find(int p){//Ѱ��p�ĸ��ڵ�
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

void merge(int p, int q){//��ͨp q (�ϲ�p q�ļ���)
	int i = find(p);//��ȡp���ڵ�
	int j = find(q);//��ȡq���ڵ�
	if (i == j){
		flag=true;//���ڳɻ�����
		return;//���ڵ���ͬ ��������
	}

	if     (h[i] == h[j]){ id[j] = i; h[i]++; }//һ������iΪ�� j������
	else if(h[i] >  h[j]){ id[j] = i; }//i�� j������
	else                 { id[i] = j; }//j�� i������
	ucount--;//p q�ϲ� ����һ������
}

bool connected(int p, int q){ return find(p) == find(q); }//p q�Ƿ���ͨ (p q�Ƿ���ͬһ������)
//Union-Find ���鼯 end ----------

int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int a,b;
	while(~scanf("%d%d",&a,&b)){
		if(a==-1&&b==-1)break;
		else if(a==0&&b==0){
			printf("Yes\n");
			continue;
		}
		else{
			first(100001);
			merge(a,b);
			map.insert(a);
			map.insert(b);
		}
		while(~scanf("%d%d",&a,&b)){
			if(a==0&&b==0)break;
			else if(flag==1)continue;
			merge(a,b);
			map.insert(a);
			map.insert(b);
		}
		if(flag==1||(ucount+map.size())!=1)
			printf("No\n");
		else
			printf("Yes\n");
	}
    return 0;
}
