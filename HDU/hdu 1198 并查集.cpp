//#define LOCAL
#include <cstdio>

//Union-Find ���鼯 start----------
int id[2550],h[2550]; //id[i]��ʾi�ĸ��ڵ� h[i]��ʾi�ĸ߶�
int re[2550][4];
int ucount; //��ͨ������ ʹ��countҪע��

void first(int n){//��ʼ������
	ucount = n;
	for (int i = 0; i < n; i++){ id[i] = i;h[i] = 1; re[i][0]=re[i][1]=re[i][2]=re[i][3]=-1; }//��ʼ��id �� ����h
}

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
	if (i == j)return;//���ڵ���ͬ ��������
	if     (h[i] == h[j]){ id[j] = i; h[i]++; }//һ������iΪ�� j������
	else if(h[i] >  h[j]){ id[j] = i; }//i�� j������
	else                 { id[i] = j; }//j�� i������
	ucount--;//p q�ϲ� ����һ������
}

bool connected(int p, int q){ return find(p) == find(q); }//p q�Ƿ���ͨ (p q�Ƿ���ͬһ������)
//Union-Find ���鼯 end ----------

//id=n*i+j
int dir[5][2]={{},{-1,0},{0,1},{1,0},{0,-1}};//�� 1 �� 2 �� 3 �� 4
int c[11][4]={{1,4},{1,2},{3,4},{2,3},{1,3},{2,4},{1,2,4},{1,3,4},{2,3,4},{1,2,3},{1,2,3,4}};
char str[51][51];


int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int m,n;
	while(~scanf("%d%d",&m,&n)){
		if(m==-1&&n==-1)break;
		first(n*m);
		for(int i=0;i<m;i++)scanf("%s",str[i]);
		int temp,p,q;
		for(int i=0;i<m;i++){//�� m
			for(int j=0;j<n;j++){//�� n
				p=n*i+j;//(i,j) id
				temp=str[i][j]-'A';
				for(int k=0;c[temp][k]!=0&&k<4;k++){//��ȡ����A-K ת�������ӷ���
					int ti=i+dir[c[temp][k]][0];
					int tj=j+dir[c[temp][k]][1];
					if(ti<0||ti>=m||tj<0||tj>=n)continue;//�жϵ����Ƿ������
					q=n*ti+tj;
					re[p][k]=q;
					for(int l=0;l<4;l++){
						if(re[q][l]==p){
							merge(p,q);break;
						}
					}
				}
			}
		}
		printf("%d\n",ucount);
	}
    return 0;
}
