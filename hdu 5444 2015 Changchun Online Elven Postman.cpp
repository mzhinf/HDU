/*
	2015 ACMICPC Asia Regional Changchun Online
	Elven Postman

	给出中序和先序 画二叉树

*/
#include <cstdio>

struct Node {//节点
	int v;
	bool have_value;
	Node *left,*right;
	Node():have_value(false),left(NULL),right(NULL){}
};

Node* newnode() { return new Node(); }

Node* del_tree(int n,int *pre,int *mid){
	int root = pre[0],i,left_n,right_n;
	Node *head,*temp;
	//确定左右子树
	for(i=0;mid[i]!=root&&i<n;i++);//得到i
	//pre 1 -- i 左子树 i+1 -- n-1右子树 根0
	//mid 0 -- i-1左子树 i+1 -- n-1右子树 根i
	//左子树数目 i  右子树数目 n-i-1
	left_n=i;
	right_n=n-i-1;

	//处理根节点
	head = newnode();
	head -> v = pre[0];
	head -> have_value =true;
	//处理左子树
	if(left_n == 0);
	else if(left_n == 1){
		temp = head -> left = newnode();
		temp -> v = pre[1];
		temp -> have_value =true;
	}
	else head -> left = del_tree(left_n, &pre[1], &mid[0]);
	//处理右子树
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
