#include <bits/stdc++.h>
using namespace std;

const int maxv = 500;
const int inf = 0x7fffffff;
int n, m;
struct edge{
	int v, length, time;
	edge(int vv, int ll, int tt){
		v = vv;
		length = ll;
		time = tt;
	}
}; 
vector<edge> adj[maxv];
vector<int> prel[maxv];
vector<int> pret[maxv];
bool vis[maxv] = {false};
int l[maxv], t[maxv];

void DijLength(int s){
	fill(vis, vis+maxv, false);
	fill(l, l+maxv, inf);
	l[s] = 0;
	for(int i=0; i<n; i++){
		int u = -1, min = inf;
		for(int j=0; j<n; j++){
			if(!vis[j] && l[j]<min){
				u = j;
				min = l[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int j=0; j<adj[u].size(); j++){
			int v = adj[u][j].v;
			if(!vis[v]){
				if(l[u]+adj[u][j].length < l[v]){
					l[v] = l[u]+adj[u][j].length;
					prel[v].clear();
					prel[v].push_back(u);
				}else if(l[u]+adj[u][j].length == l[v]){
					prel[v].push_back(u);
				}	
			}
		}
	}
}

void DijTime(int s){
	fill(vis, vis+maxv, false);
	fill(t, t+maxv, inf);
	t[s] = 0;
	for(int i=0; i<n; i++){
		int u = -1, min = inf;
		for(int j=0; j<n; j++){
			if(!vis[j] && t[j]<min){
				u = j;
				min = t[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int j=0; j<adj[u].size(); j++){
			int v = adj[u][j].v;
			if(!vis[v]){
				if(t[u]+adj[u][j].time < t[v]){
					t[v] = t[u]+adj[u][j].time;
					pret[v].clear();
					pret[v].push_back(u);
				}else if(t[u]+adj[u][j].time == t[v]){
					pret[v].push_back(u);
				}	
			}
		}
	}
}

vector<int> temPath, path;
int fastTime = inf;
void DFSL(int s, int d){
	if(d == s){
		temPath.push_back(s);
		int time = 0;
		for(int i=temPath.size()-1; i>0; i--){
			int u = temPath[i], v = temPath[i-1], j;
			for(j=0; j<adj[u].size(); j++){
				if(adj[u][j].v == v){
					time += adj[u][j].time;
					break;
				}
			}
		}
		if(time < fastTime){
			fastTime = time;
			path = temPath;
		}
		temPath.pop_back();
		return;
	}
	temPath.push_back(d);
	for(int i=0; i<prel[d].size(); i++){
		DFSL(s, prel[d][i]);
	}
	temPath.pop_back();
}

vector<int> temPathT, pathT;
int minNode = inf;
void DFST(int s, int d){
	if(d == s){
		temPathT.push_back(s);
		if(temPathT.size() < minNode){
			minNode = temPathT.size();
			pathT = temPathT;
		}
		temPathT.pop_back();
		return;
	}
	temPathT.push_back(d);
	for(int i=0; i<pret[d].size(); i++){
		DFST(s, pret[d][i]);
	}
	temPathT.pop_back();
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int v1, v2, oneway, length, time;
		cin>>v1>>v2>>oneway>>length>>time;
		adj[v1].push_back(edge(v2, length, time));
		if(!oneway){
			adj[v2].push_back(edge(v1, length, time));
		}
	}
	int source, destination;
	cin>>source>>destination;
	DijLength(source);
	DijTime(source);
	DFSL(source, destination);
	DFST(source, destination);
	if(path == pathT){
		cout<<"Distance = "<<l[destination]<<"; Time = "<<t[destination]<<": "<<source;
		for(int i=path.size()-2; i>=0; i--){
			cout<<" -> "<<path[i];
		}
	}
	else{
		cout<<"Distance = "<<l[destination]<<": "<<source;
		for(int i=path.size()-2; i>=0; i--){
			cout<<" -> "<<path[i];
		}
		cout<<endl<<"Time = "<<t[destination]<<": "<<source;
		for(int i=pathT.size()-2; i>=0; i--){
			cout<<" -> "<<pathT[i];
		}
	}
}
