#include <bits/stdc++.h>
using namespace std;

const int maxv = 600;
const int inf = 0x7fffffff;
int cmax, n, sp, m, half;
int G[maxv][maxv];
int current[maxv];
int d[maxv];
bool vis[maxv] = {false};
vector<int> pre[maxv];
void Dijkstra(){
	fill(d, d+maxv, inf);
	d[0] = 0;
	for(int i=0; i<=n; i++){
		int u = -1, min = inf;
		for(int j=0; j<=n; j++){
			if(!vis[j] && d[j]<min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v=0; v<=n; v++){
			if(!vis[v] && G[u][v]!=inf){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u] + G[u][v] == d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
vector<int> temPath, path;
int send = inf, back = inf;
void dfs(int v){
	if(v == 0){
		temPath.push_back(v);
		int sd = 0, bk = 0;
		for(int i=temPath.size()-2; i>=0; i--){
			int bike = half - current[temPath[i]];
			if(bike > 0){
				if(bk - bike < 0){
					sd += bike - bk;
					bk = 0;
				}else{
					bk -= bike;
				}
			}else if(bike < 0){
				bk += abs(bike);
			}
		}
		if(sd < send){
			send = sd;
			back = bk;
			path = temPath;
		}else if(sd == send && bk < back){
			back = bk;
			path = temPath;
		}
		temPath.pop_back();
		return;
	}
	temPath.push_back(v);
	for(int i : pre[v]){
		dfs(i);
	}
	temPath.pop_back();
}


int main(){
	ios::sync_with_stdio(false);
	fill(G[0], G[0]+maxv*maxv, inf);
	cin>>cmax>>n>>sp>>m;
	half = cmax / 2;
	for(int i=1; i<=n; i++){
		int temp;
		cin>>temp;
		current[i] = temp;
	}
	for(int i=0; i<m; i++){
		int u, v, dis;
		cin>>u>>v>>dis;
		if(G[u][v] > dis){
			G[u][v] = G[v][u] = dis;
		}
	}
	Dijkstra();
	dfs(sp);
	cout<<send<<' ';
	for(int i=path.size()-1; i>0; i--){
		cout<<path[i]<<"->";
	}
	cout<<path[0]<<' '<<back;
}
