//#define LOCAL
#include <cstdio>

//Union-Find ���鼯 start----------
#define N 1000
int id[N],h[N]; //id[i]��ʾi�ĸ��ڵ� h[i]��ʾi�ĸ߶�
int count; //��ͨ������
void first(int n){//��ʼ������
	count = n;
	for (int i = 1; i <= n; i++){ id[i] = i;h[i] = 1; }//��ʼ��id �� ����h
}
int find(int p){
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
void merge(int p, int q){
	int i = find(p);//��ȡp���ڵ�
	int j = find(q);//��ȡq���ڵ�
	if (i == j) return;//���ڵ���ͬ ��������

	if     (h[i] == h[j]){ id[j] = i; h[i]++; }//һ������iΪ�� j������
	else if(h[i] >  h[j]){ id[j] = i; }//i�� j������
	else                 { id[i] = j; }//j�� i������
	count--;//p q�ϲ� ����һ������
}
bool connected(int p, int q){ return find(p) == find(q); }//p q �Ƿ���ͨ
//Union-Find ���鼯 end ----------

int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n,m;
    while(~scanf("%d",&n)&&n!=0){
    	first(n);
    	scanf("%d",&m);
    	int x,y;
    	for(int i=0;i<m;i++){
    		scanf("%d%d",&x,&y);
    		merge(x,y);
    	}
    	printf("%d\n",count-1);
    }
    return 0;
}
