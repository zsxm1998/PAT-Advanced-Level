#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10;
int have[MAXN] = {0}, n;
struct node{
	int lchild = -1, rchild = -1;
}tree[MAXN];
void level(int root){
	int cnt = 0;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		cnt++;
		cout<<u<<(cnt==n?'\n':' ');
		if(tree[u].rchild != -1) q.push(tree[u].rchild);
		if(tree[u].lchild != -1) q.push(tree[u].lchild);
	}
}
vector<int> inseq;
void in(int u){
	if(tree[u].rchild != -1) in(tree[u].rchild);
	inseq.push_back(u);
	if(tree[u].lchild != -1) in(tree[u].lchild);
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		string l, r;
		cin>>l>>r;
		if(l != "-"){
			tree[i].lchild = stoi(l);
			have[stoi(l)]++;
		}
		if(r != "-"){
			tree[i].rchild = stoi(r);
			have[stoi(r)]++;
		}
	}
	int root = 0;
	while(have[root]) root++;
	level(root);
	in(root);
	for(int i=0; i<n; i++){
		if(i != 0) cout<<' ';
		cout<<inseq[i];
	}
	return 0;
}

