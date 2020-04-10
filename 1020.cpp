#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;

struct Node{
	int data;
	Node *lchild, *rchild;
	Node(int d, Node* l=NULL, Node* r=NULL):data(d),lchild(l),rchild(r){}
};

int in[MAXN], pst[MAXN];

Node* buildTreeFromInAndPst(int pstr, int inl, int inr){
	if(inl>inr){//�������г���Ϊ0��ֱ�ӷ���NULL 
		return NULL;
	}
	int i;//�ҵ����ڵ����������е�λ�ã���i�洢 
	for(i=inr;in[i]!=pst[pstr];i--);
	int numr = inr - i;//�������ڵ���� 
	Node* root = new Node(in[i]);
	root->lchild = buildTreeFromInAndPst(pstr-numr-1,inl, i-1);
	root->rchild = buildTreeFromInAndPst(pstr-1, i+1, inr);
	return root;
}

void levelorder(Node* root){//�����ӡ 
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
		cin>>pst[i];
	}
	for(int i=0; i<n; i++){
		cin>>in[i];
	}
	Node* root = buildTreeFromInAndPst(n-1, 0, n-1);
	levelorder(root);
}
