#include <bits/stdc++.h>
using namespace std;
struct node{
	int lchild, rchild, data;
}tree[100];
int n, seq[100], cnt = 0;
void inorder(int root){
	if(root == -1) return;
	inorder(tree[root].lchild);
	tree[root].data = seq[cnt++];
	inorder(tree[root].rchild);
}
void levelorder(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(tree[u].lchild != -1) q.push(tree[u].lchild);
		if(tree[u].rchild != -1) q.push(tree[u].rchild);
		cout<<tree[u].data;
		if(!q.empty()) cout<<' ';
	}
}
int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0; i<n; i++) cin>>tree[i].lchild>>tree[i].rchild;
	for(int i=0; i<n; i++) cin>>seq[i];
	sort(seq, seq+n);
	inorder(0);
	levelorder(0);
	return 0;
}

