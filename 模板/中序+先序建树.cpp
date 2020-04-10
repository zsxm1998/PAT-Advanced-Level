#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50010;

struct Node{
	int data;
	Node *lchild, *rchild;
	Node(int d, Node* l=NULL, Node* r=NULL):data(d),lchild(l),rchild(r){}
};

int pre[MAXN], in[MAXN];

Node* buildTreeFromInAndPre(int prel, int inl, int inr){
	if(inl>inr){//�������г���Ϊ0��ֱ�ӷ���NULL 
		return NULL;
	}
	int i;//�ҵ����ڵ����������е�λ�ã���i�洢 
	for(i=inl;in[i]!=pre[prel];i++);
	int numl = i - inl;//�������ڵ���� 
	Node* root = new Node(in[i]);
	root->lchild = buildTreeFromInAndPre(prel+1,inl, i-1);
	root->rchild = buildTreeFromInAndPre(prel+numl+1, i+1, inr);
	return root;
}

void postorder(Node* root){//�����������
	if(root == NULL){
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	cout<< root->data<<' '; 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>pre[i];
	}
	for(int i=0; i<n; i++){
		cin>>in[i];
	}
	Node* root = buildTreeFromInAndPre(0, 0, n-1);
	postorder(root);
}
