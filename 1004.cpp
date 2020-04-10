#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100], output;
bool vis[100] = {false};
void dfs(int u, int level){
	vis[u] = true;
	if(adj[u].size() == 0){
		if(level+1 > output.size()) output.resize(level+1);
		output[level]++;
	}else{
		for(int i=0; i<adj[u].size(); i++){
			if(vis[adj[u][i]] == false) dfs(adj[u][i], level+1);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin>>n;
	if(n == 0) return 0;
	cin>>m;
	for(int i=0; i<m; i++){
		int id, k;
		cin>>id>>k;
		adj[id].resize(k);
		for(int j=0; j<k; j++) cin>>adj[id][j];
	}
	dfs(1, 0);
	for(int i=0; i<output.size(); i++){
		if(i != 0) cout<<' ';
		cout<<output[i];
	}
	return 0;
}

