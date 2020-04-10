#include <bits/stdc++.h>
using namespace std;
struct node{
	int data, height, depth;
	node *lchild, *rchild;
	node(int x){
		data = x;
		height = 1;
		lchild = rchild = NULL;
	}
};
int getHeight(node* root){
	if(root == NULL) return 0;
	else return root->height;
}
void insert(node* &root, int x){
	if(root == NULL){
		root = new node(x);
		return;
	}
	if(x <= root->data){
		insert(root->lchild, x);
		root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
	}else{
		insert(root->rchild, x);
		root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
	}
}
int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	node* tree = NULL;
	while(n--){
		int temp;
		cin>>temp;
		insert(tree, temp);
	}
	int high = getHeight(tree), n1 = 0, n2 = 0;
	queue<node*> q;
	tree->depth = 1;
	q.push(tree);
	while(!q.empty()){
		node* root = q.front();
		q.pop();
		if(root->depth == high){
			n1++;
		}else if(root->depth == high-1){
			n2++;
		}
		if(root->lchild != NULL){
			root->lchild->depth = root->depth + 1;
			q.push(root->lchild);
		}
		if(root->rchild != NULL){
			root->rchild->depth = root->depth + 1;
			q.push(root->rchild);
		}
	}
	cout<<n1<<" + "<<n2<<" = "<<n1+n2;
	return 0;
}

