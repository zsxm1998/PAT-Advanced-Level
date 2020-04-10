#include <bits/stdc++.h>
using namespace std;

struct node{
	int data, height;
	node *lchild, *rchild;
	node(int x){
		data = x;
		height = 1;//�ڵ��ʼ�߶�Ϊ1 
		lchild = rchild = NULL;
	}
};

int getHeight(node* root){//��ȡ���� 
	if(root == NULL){
		return 0;//�����߶�Ϊ0 
	}
	else{
		return root->height;
	} 
}

int getBalanceFactor(node* root){//��ȡƽ������ 
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* root){//�������� 
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void search(node* root, int x){//���� 
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

void L(node* &root){//���� 
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);//�������� 
	updateHeight(temp);//�������ߣ������治�ܵߵ� 
	root = temp;
} 

void R(node* &root){//���� 
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);//�������� 
	updateHeight(temp);//�������ߣ������治�ܵߵ� 
	root = temp;
} 

void insert(node* &root, int x){//����ڵ� 
	if(root == NULL){
		root = new node(x);
		return;
	}
	if(x < root->data){
		insert(root->lchild, x);
		updateHeight(root);
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->lchild) == 1){//LL�� 
				R(root);
			}
			else if(getBalanceFactor(root->lchild) == -1){//LR�� 
				L(root->lchild);
				R(root); 
			}
		}
	}
	else{
		insert(root->rchild, x);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->lchild) == -1){//RR�� 
				L(root);
			}
			else if(getBalanceFactor(root->lchild) == 1){//RL�� 
				R(root->rchild);
				L(root); 
			}
		}
	}
} 

node* create(int data[], int n){//����AVL�� 
	node* root = NULL;
	for(int i=0; i<n; i++) insert(root, data[i]);
	return root;
}

int main(){
	return 0;
} 
