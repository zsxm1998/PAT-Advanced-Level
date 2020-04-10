#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;

struct Node{
	int data;
	Node *lchild, *rchild;
	Node(int d, Node* l=NULL, Node* r=NULL):data(d),lchild(l),rchild(r){}
};

int in[MAXN], post[MAXN];

Node* buildTreeFromInAndPost(int postr, int inl, int inr){
	if(inl>inr){//中序序列长度为0则直接返回NULL 
		return NULL;
	}
	int i;//找到根节点在中序序列的位置，用i存储 
	for(i=inr;in[i]!=post[postr];i--);
	int numr = inr - i;//右子树节点个数 
	Node* root = new Node(in[i]);
	root->lchild = buildTreeFromInAndPost(postr-numr-1,inl, i-1);
	root->rchild = buildTreeFromInAndPost(postr-1, i+1, inr);
	return root;
}

void levelorder(Node* root){//层序打印 
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* nd = q.front();
		q.pop();
		cout<<nd->data;
		if(nd->lchild != NULL){
			q.push(nd->lchild);
		}
		if(nd->rchild != NULL){
			q.push(nd->rchild);
		}
		if(!q.empty()){
			cout<<' ';
		} 
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>post[i];
	}
	for(int i=0; i<n; i++){
		cin>>in[i];
	}
	Node* root = buildTreeFromInAndPost(n-1, 0, n-1);
	levelorder(root);
}
