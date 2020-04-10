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
stringstream ss;//����һ��stringstream������ضԲ�ͬ�������������ӳ��ַ��� 
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
		ss.clear();//�����״̬ 
		ss.str("");//��������ݣ���仰���Բ�Ҫ 
		dfs(i);
		ss>>tempOut;
		if(tempOut.size() > output.size()){
			output = tempOut;
		}
	}
	if(output.size()>1){//����������У�ƾ��ͨ������2 
		cout<<output.substr(1, output.size()-2);
	}else{
		cout<<output;
	}	
}
