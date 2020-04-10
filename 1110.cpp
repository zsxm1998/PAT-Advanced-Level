#include <bits/stdc++.h>//�����ʼ����ʱ���Ҿ�Ȼ��char�������֣��������ֿ�������λ���ʵ����м������Ե���� 
using namespace std;//��ֱ���ҵ����ڵ�ķ��������ʼ� 
const int MAXN = 20;
int n;
struct node{
	int lchild = -1, rchild = -1;
}tree[MAXN];
bool judgeComplete(int root, int &last, int &cnt){
	bool noChild = false, complete = true;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		last = q.front();
		q.pop();
		cnt++;
		if(tree[last].lchild == -1){
			noChild = true;
		}else{
			if(noChild) complete = false;
			q.push(tree[last].lchild);
		}
		if(tree[last].rchild == -1){
			noChild = true;
		}else{
			if(noChild)complete = false;
			q.push(tree[last].rchild);
		}
	}
	return complete;
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		string a, b;
		cin>>a>>b;
		if(a != "-") tree[i].lchild = stoi(a);
		if(b != "-") tree[i].rchild = stoi(b);
	}
	int maxnum = 0, root=0, last=0;
	bool complete = true;
	for(int i=0; i<n; i++){
		int l=0, cnt=0;
		if(judgeComplete(i, l, cnt) == false) complete = false;
		if(cnt > maxnum){
			maxnum = cnt;
			root = i;
			last = l;
		}
	}
	if(complete) cout<<"YES "<<last;
	else cout<<"NO "<<root;
	return 0;
}

