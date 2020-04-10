#include <bits/stdc++.h>
using namespace std;

struct node{
	int data, height;
	node *lchild, *rchild;
	node(int x){
		data = x;
		height = 1;//节点初始高度为1 
		lchild = rchild = NULL;
	}
};

int getHeight(node* root){//获取树高 
	if(root == NULL){
		return 0;//空树高度为0 
	}
	else{
		return root->height;
	} 
}

int getBalanceFactor(node* root){//获取平衡因子 
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* root){//更新树高 
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void search(node* root, int x){//搜索 
	if(root = NULL){
		cout<<"search failed"<<endl;
		return;
	}
	if(x == root->data){
		cout<<root->data<<endl;
	}
	else if(x < root->data){
		search(root->lchild, x);
	}
	else if(x > root->data){
		search(root->rchild, x);
	}
	
}

void L(node* &root){//左旋 
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);//更新树高 
	updateHeight(temp);//更新树高，和上面不能颠倒 
	root = temp;
} 

void R(node* &root){//右旋 
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);//更新树高 
	updateHeight(temp);//更新树高，和上面不能颠倒 
	root = temp;
} 

void insert(node* &root, int x){//插入节点 
	if(root == NULL){
		root = new node(x);
		return;
	}
	if(x < root->data){
		insert(root->lchild, x);
		updateHeight(root);
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->lchild) == 1){//LL型 
				R(root);
			}
			else if(getBalanceFactor(root->lchild) == -1){//LR型 
				L(root->lchild);
				R(root); 
			}
		}
	}
	else{
		insert(root->rchild, x);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->lchild) == -1){//RR型 
				L(root);
			}
			else if(getBalanceFactor(root->lchild) == 1){//RL型 
				R(root->rchild);
				L(root); 
			}
		}
	}
} 

node* create(int data[], int n){//创建AVL树 
	node* root = NULL;
	for(int i=0; i<n; i++) insert(root, data[i]);
	return root;
}

int main(){
	return 0;
} 
