#include <bits/stdc++.h>
using namespace std;
const int MAXV = 10000;
int start, dest;//�����յ� 
struct edge{
	int v, line;
	friend bool operator<(const edge &a, const edge &b){//�ṹ�������������С�ںţ����������const 
		return a.v != b.v ? a.v < b.v : a.line < b.line;
	} 
};
set<edge> adj[MAXV];//Ϊ�˷�ֹ1-2-1���������в����ظ��ıߣ�����set������vector 
bool vis[MAXV] = {false};
vector<edge> tempPath, path;
int transfer;
void dfs(int u){
	if(u == dest){
		int trans = 0, preline = tempPath[0].line;
		for(auto it : tempPath){
			if(it.line != preline){
				trans++;
				preline = it.line;
			}
		}
		if(tempPath.size() < path.size()){
			path = tempPath;
			transfer = trans;
		}else if(tempPath.size()==path.size() && trans<transfer){
			path = tempPath;
			transfer = trans;
		}
		return;
	}
	vis[u] = true;
	for(auto it : adj[u]){
		int v = it.v;
		if(!vis[v]){
			tempPath.push_back(it);
			dfs(v);
			tempPath.pop_back();
		}
	}
	vis[u] = false;
}
void printPath(){
	cout<<path.size()<<endl;
	int from = start, to, preline = path[0].line, prev = start;
	for(auto it : path){
		if(it.line != preline){
			to = prev;
			cout<<"Take Line#"<<preline<<" from "<<setw(4)<<from<<" to "<<setw(4)<<to<<".\n";
			from = to;
		}
		preline = it.line;
		prev = it.v;
	}
	//�����������һ��·������䲻�ܺ������ѭ������һ��
	//���򵱵����ڶ�վ�ǻ���վʱ�޷�������һ��·�� 
	to = dest;
	cout<<"Take Line#"<<preline<<" from "<<setw(4)<<from<<" to "<<setw(4)<<to<<".\n";
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		int m, pre, now;
		cin>>m>>pre;
		for(int j=1; j<m; j++){
			cin>>now;
			adj[pre].insert(edge{now, i});
			adj[now].insert(edge{pre, i});
			pre = now;
		}
	}
	int k;
	cin>>k;
	cout<<setfill('0');
	for(int i=0; i<k; i++){
		transfer = 0x7fffffff;
		path.resize(10010);
		cin>>start>>dest;
		dfs(start);
		printPath();
	}
}
