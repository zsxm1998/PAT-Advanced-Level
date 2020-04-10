#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10001;
int n;
vector<int> adj[MAXN];
bool vis[MAXN];
int bfs(int root, bool flag){
	if(flag) fill(vis, vis+MAXN, false);
	int total = 0, level = 0, thislcnt = 1, nextlcnt = 0;
	queue<int> q;
	q.push(root);
	vis[root] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		total++;
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i];
			if(vis[v] == false){
				q.push(v);
				vis[v] = true;
				nextlcnt++;
			}
		}
		thislcnt--;
		if(thislcnt == 0){
			thislcnt = nextlcnt;
			nextlcnt = 0;
			level++;
		}
	}
	if(total != n) return -1;
	else return level;
} 
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1; i<n; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	set<int> out;
	int deepest = 0;
	for(int i=1; i<=n; i++){
		int deepth = bfs(i, true);
		if(deepth == -1){
			fill(vis, vis+MAXN, false);
			int k = 0;
			for(int j=1; j<=n; j++){
				if(vis[j] == false){
					bfs(j, false);
					k++;
				}
			}
			cout<<"Error: "<<k<<" components";
			return 0;
		}else if(deepth > deepest){
			deepest = deepth;
			out.clear();
			out.insert(i);
		}else if(deepth == deepest) out.insert(i);
	}
	for(auto t : out) cout<<t<<endl;
	return 0;
}

