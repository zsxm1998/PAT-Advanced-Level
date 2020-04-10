#include <bits/stdc++.h>
using namespace std;
struct node{
	string data;
	int lchild, rchild;
	node(string s, int l, int r){
		data = s;
		lchild = l;
		rchild = r;
	}
	node(){};
}tree[30];
stringstream ss;//创建一个stringstream来方便地对不同是数据类型连接成字符串 
void dfs(int root){
	if(tree[root].lchild==-1 && tree[root].rchild==-1){
		ss<<tree[root].data;
		return;
	}
	ss<<'(';
	if(tree[root].lchild != -1)
		dfs(tree[root].lchild);
	ss<<tree[root].data;
	if(tree[root].rchild != -1)
		dfs(tree[root].rchild);
	ss<<')';
}
int main(){
	//freopen("input.txt", "r", stdin);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		string inputS;
		int inputL, inputR;
		cin>>inputS>>inputL>>inputR;
		tree[i] = node(inputS, inputL, inputR);
	}
	string output, tempOut;
	for(int i=1; i<=n; i++){
		ss.clear();//清空流状态 
		ss.str("");//清空流内容，这句话可以不要 
		dfs(i);
		ss>>tempOut;
		if(tempOut.size() > output.size()){
			output = tempOut;
		}
	}
	if(output.size()>1){//特殊情况特判，凭此通过检查点2 
		cout<<output.substr(1, output.size()-2);
	}else{
		cout<<output;
	}	
}
