#include <bits/stdc++.h>
using namespace std;
struct node{
	int data, color;
	node *lchild, *rchild;
	node(int d, int c){
		data = d;
		color = c;
		lchild = rchild = NULL;
	}
};
const int maxv = 10000;//N虽然<=30但是并不代表数据的大小<=30 
int pre[maxv], in[maxv], color[maxv];//黑1红0 
node* buildTree(int prel, int prer, int inl, int inr){
	if(prel > prer){
		return NULL;
	}
	int data = pre[prel];
	int mid;
	for(mid=inl; mid<=inr && in[mid]!=data; mid++){}
	int numl = mid - inl;
	node* root = new node(data, color[data]);
	root->lchild = buildTree(prel+1, prel+numl, inl, mid-1);
	root->rchild = buildTree(prel+numl+1, prer, mid+1, inr);
	return root;
}
int dfs(node* root){
	if(root == NULL) return 1;
	if(root->color == 0){
		if(root->lchild!=NULL && root->lchild->color==0) return -1;
		if(root->rchild!=NULL && root->rchild->color==0) return -1;
	}
	int lenthL = dfs(root->lchild);
	if(lenthL == -1) return -1;
	int lenthR = dfs(root->rchild);
	if(lenthR == -1) return -1;
	if(lenthL == lenthR) return lenthL + root->color;
	else return -1;
}
int main(){
	ios::sync_with_stdio(false);
	int k;
	cin>>k;
	for(int i=0; i<k; i++){
		int n;
		cin>>n;
		for(int j=0; j<n; j++){
			int input;
			cin>>input;
			if(input > 0){
				color[input] = 1;
				pre[j] = input;
			}else{
				color[-input] = 0;
				pre[j] = -input;
			}
		}
		if(color[pre[0]] == 0){
			cout<<"No\n";
			continue;
		}
		for(int j=0; j<n; j++){
			in[j] = pre[j];
		}
		sort(in, in+n);
		node* root = buildTree(0, n-1, 0, n-1);
		if(dfs(root) == -1){
			cout<<"No\n";
		}else{
			cout<<"Yes\n";
		}
	}
}
