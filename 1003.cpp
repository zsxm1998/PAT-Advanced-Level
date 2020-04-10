#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500;
const int INF = 0x3fffffff;
int n, m, c1, c2;
struct edge{
	int v, len;
	edge(int vv, int ll){
		v = vv;
		len = ll;
	}
};
vector<edge> adj[MAXN];
int weight[MAXN];
bool vis[MAXN] = {false};
int d[MAXN], w[MAXN]={0}, cnt[MAXN];
void Dijkstra(int s){
	fill(d, d+MAXN, INF);
	d[s] = 0;
	cnt[s] = 1;
	w[s] = weight[s];
	for(int i=0; i<n; i++){
		int u = -1, min = INF;
		for(int j=0; j<n; j++){
			if(!vis[j] && d[j]<min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int j=0; j<adj[u].size(); j++){
			int v = adj[u][j].v, len = adj[u][j].len;
			if(vis[v] == false){
				if(d[u] + len < d[v]){
					d[v] = d[u] + len;
					cnt[v] = cnt[u];
					w[v] = w[u] + weight[v];
				}else if(d[u] + len == d[v]){
					cnt[v] += cnt[u];
					if(w[u] + weight[v] > w[v]){
						w[v] = w[u] + weight[v];
					}
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>c1>>c2;
	for(int i=0; i<n; i++) cin>>weight[i];
	for(int i=0; i<m; i++){
		int u, v, l;
		cin>>u>>v>>l;
		adj[u].push_back(edge(v, l));
		adj[v].push_back(edge(u, l));
	}
	Dijkstra(c1);
	cout<<cnt[c2]<<' '<<w[c2];
	return 0;
}

