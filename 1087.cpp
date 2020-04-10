#include <bits/stdc++.h>
using namespace std;

const int maxv = 200;
const int inf = 0x3fffffff;
int n, k;
string city[maxv];
int happy[maxv];

int sti(string s){
	for(int i=0; i<n; i++){
		if(city[i] == s) return i;
	}
	return -1;
}

int G[maxv][maxv];
bool vis[maxv] = {false};
int c[maxv];
vector<int> pre[maxv];

void Dijkstra(int s){
	fill(c, c + maxv, inf);
	c[s] = 0;
	for(int i=0; i<n; i++){
		int u = -1, min = inf;
		for(int j=0; j<n; j++){
			if(!vis[j] && c[j]<min){
				u = j;
				min = c[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v=0; v<n; v++){
			if(!vis[v] && G[u][v] != inf){
				if(c[u] + G[u][v] < c[v]){
					c[v] = c[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(c[u] + G[u][v] == c[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

vector<int> temPath, path;
int maxhappy = -1, pathNum = 0;
double maxavghappy = -1;
void DFS(int d){
	if(d == 0){
		temPath.push_back(d);
		pathNum++;
		int hap = 0;
		for(int i=0; i<temPath.size()-1; i++){
			hap += happy[temPath[i]];
		}
		double avghap = (double)hap / (temPath.size()-1);
		if(hap > maxhappy){
			path = temPath;
			maxhappy = hap;
			maxavghappy = avghap;
		}else if(hap == maxhappy && avghap>maxavghappy){
			path = temPath;
			maxavghappy = avghap;
		}
		temPath.pop_back();
		return;
	}
	temPath.push_back(d);
	for(int i=0; i<pre[d].size(); i++){
		DFS(pre[d][i]);
	}
	temPath.pop_back();
}

int main(){
	ios::sync_with_stdio(false);
	string source, destination = "ROM";
	cin>>n>>k>>source;
	city[0] = source;
	for(int i=1; i<n; i++){
		string ci;
		int ha;
		cin>>ci>>ha;
		city[i] = ci;
		happy[i] = ha;
	}
	fill(G[0], G[0] + maxv * maxv, inf);
	for(int i=0; i<k; i++){
		string us, vs;
		int cost;
		cin>>us>>vs>>cost;
		int u = sti(us), v = sti(vs);
		G[u][v] = G[v][u] = cost;
	}
	Dijkstra(0);
	DFS(sti(destination));
	cout<<pathNum<<' '<<c[sti(destination)]<<' '<<maxhappy<<' '<<(int)maxavghappy<<endl;
	for(int i=path.size()-1; i>0; i--){
		cout<<city[path[i]]<<"->";
	}
	cout<<destination;
}
