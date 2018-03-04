/*
	2015 ACMICPC Asia Regional Changchun Online
	Elven Postman

	������������� ��������

*/
#include <cstdio>

struct Node {//�ڵ�
	int v;
	bool have_value;
	Node *left,*right;
	Node():have_value(false),left(NULL),right(NULL){}
};

Node* newnode() { return new Node(); }

Node* del_tree(int n,int *pre,int *mid){
	int root = pre[0],i,left_n,right_n;
	Node *head,*temp;
	//ȷ����������
	for(i=0;mid[i]!=root&&i<n;i++);//�õ�i
	//pre 1 -- i ������ i+1 -- n-1������ ��0
	//mid 0 -- i-1������ i+1 -- n-1������ ��i
	//��������Ŀ i  ��������Ŀ n-i-1
	left_n=i;
	right_n=n-i-1;

	//������ڵ�
	head = newnode();
	head -> v = pre[0];
	head -> have_value =true;
	//����������
	if(left_n == 0);
	else if(left_n == 1){
		temp = head -> left = newnode();
		temp -> v = pre[1];
		temp -> have_value =true;
	}
	else head -> left = del_tree(left_n, &pre[1], &mid[0]);
	//����������
	if(right_n == 0);
	else if(right_n == 1){
		temp = head -> right = newnode();
		temp -> v = pre[i+1];
		temp -> have_value =true;
	}
	else head -> right = del_tree(right_n, &pre[i+1], &mid[i+1]);
	return head;
}

void remove_tree(Node* u){
    if(u == NULL) return ;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}

int main(){
	int pre[1005],mid[1005],t;
	scanf("%d",&t);
	while(t--){
		int n,m,tt;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&pre[i]);
			mid[i]=i;
		}
		Node *head = del_tree(n,pre+1,mid+1),*temp;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			temp=head;
			scanf("%d",&tt);
			while(temp->v!=tt){
				if(tt>temp->v){
					temp=temp->right;
					printf("W");
				}
				else{
					temp=temp->left;
					printf("E");
				}
			}
			printf("\n");
		}
		remove_tree(head);
	}
	return 0;
}
