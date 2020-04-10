#include <bits/stdc++.h>
using namespace std;
struct node{
	int data, height;
	node *lchild, *rchild;
	node(int x){
		data = x;
		height = 1;
		lchild = rchild = NULL;
	}
};
int getHeight(node *root){
	if(root == NULL) return 0;
	else return root->height;
}
void updateHeight(node *root){
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
int getBalance(node *root){
	return getHeight(root->lchild) - getHeight(root->rchild);
}
void L(node* &root){
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void R(node* &root){
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node* &root, int x){
	if(root == NULL){
		root =  new node(x);
		return;
	}
	if(x < root->data){
		insert(root->lchild, x);
		updateHeight(root);
		if(getBalance(root) == 2){
			if(getBalance(root->lchild) == 1){
				R(root);
			}else if(getBalance(root->lchild) == -1){
				L(root->lchild);
				R(root);
			}
		}
	}else{
		insert(root->rchild, x);
		updateHeight(root);
		if(getBalance(root) == -2){
			if(getBalance(root->rchild) == -1){
				L(root);
			}else if(getBalance(root->rchild) == 1){
				R(root->rchild);
				L(root);
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	node* tree = NULL;
	while(n--){
		int a;
		cin>>a;
		insert(tree, a);
	}
	bool haveChild = true, judgeFlag = true;
	int cnt = 0;
	queue<node*> q;
	q.push(tree);
	while(!q.empty()){
		node* root = q.front();
		q.pop();
		if(cnt) cout<<' ';
		cout<<root->data;
		cnt++;
		if(root->lchild != NULL){
			q.push(root->lchild);
			if(haveChild == false) judgeFlag = false;
		}else{
			haveChild = false;
		}
		if(root->rchild != NULL){
			q.push(root->rchild);
			if(haveChild == false) judgeFlag = false;
		}else{
			haveChild = false;
		}
	}
	if(judgeFlag) cout<<"\nYES";
	else cout<<"\nNO";
}
