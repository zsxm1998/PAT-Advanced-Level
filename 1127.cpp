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
	if(inl>inr){//中序序列长度为0则直接返回NULL 
		return NULL;
	}
	int i;//找到根节点在中序序列的位置，用i存储 
	for(i=inr;in[i]!=pst[pstr];i--);
	int numr = inr - i;//右子树节点个数 
	Node* root = new Node(in[i]);
	root->lchild = buildTreeFromInAndPst(pstr-numr-1,inl, i-1);
	root->rchild = buildTreeFromInAndPst(pstr-1, i+1, inr);
	return root;
}

void zigzaggingorder(Node* root){//Z字打印 
	stack<Node*> s1, s2;
	s1.push(root); 
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			Node* nd = s1.top();
			s1.pop();
			cout<<nd->data;
			if(nd->rchild != NULL){
				s2.push(nd->rchild);
			}
			if(nd->lchild != NULL){
				s2.push(nd->lchild);
			}
			if(!s1.empty() || !s2.empty()){
				cout<<' ';
			}
		}
		while(!s2.empty()){
			Node* nd = s2.top();
			s2.pop();
			cout<<nd->data;
			if(nd->lchild != NULL){
				s1.push(nd->lchild);
			}
			if(nd->rchild != NULL){
				s1.push(nd->rchild);
			}
			if(!s1.empty() || !s2.empty()){
				cout<<' ';
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>in[i];
	}
	for(int i=0; i<n; i++){
		cin>>pst[i];
	}
	Node* root = buildTreeFromInAndPst(n-1, 0, n-1);
	zigzaggingorder(root);
}
