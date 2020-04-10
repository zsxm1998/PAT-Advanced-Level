#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n, m, k, uu, vv, x, ans;
vector<int> adj[MAXN]; 
bool vis[1000];
//在这道题中dfs和bfs性能相差不大 
void dfs(int u){
	vis[u] = true;
	for(int i=0; i<adj[u].size(); i++){
		if(vis[adj[u][i]] == false) dfs(adj[u][i]);
	}
}
void bfs(int u){
	queue<int> q;
	q.push(u);
	vis[u] = true;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int i=0; i<adj[u].size(); i++){
			if(vis[adj[u][i]] == false){
				q.push(adj[u][i]);
				vis[adj[u][i]] = true;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=0; i<m; i++){
		cin>>uu>>vv;
		adj[uu].push_back(vv);
		adj[vv].push_back(uu);
	}
	for(int i=0; i<k; i++){
		cin>>x;
		memset(vis, false, sizeof(vis));
		vis[x] = true;
		ans = 0;
		for(int j=1; j<=n; j++){
			if(vis[j] == false){
				ans++;
				bfs(j);
			}
		}
		cout<<ans-1<<endl;
	}
	return 0;
}

