#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3fffffff;
const int maxv = 510;
int n, m, s, des;

int distc[maxv][maxv]; 
int cost[maxv][maxv];
int d[maxv], c[maxv];
bool vis[maxv] = {false};
int pre[maxv];
void Dijkstra(int s){
	for(int i=0; i<n; i++) pre[i] = i;
	fill(d, d+n, inf);
	fill(c, c+n, inf);
	d[s] = c[s] = 0;
	for(int i=0; i<n; i++){
		int u = -1, min = inf;
		for(int j=0; j<n; j++){
			if(!vis[j] && d[j]<min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v=0; v<n; v++){
			if(!vis[v] && distc[u][v]!=inf){
				if(d[u] + distc[u][v] < d[v]){
					d[v] = d[u] + distc[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}else if(d[u]+distc[u][v]==d[v] && c[u]+cost[u][v]<c[v]){
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
			}
		}
	}
}
void printAns(int index, int pr, int &tDis, int &tCost){
	if(index == s){
		cout<<index<<' ';
		tDis += distc[index][pr];
		tCost += cost[index][pr];
		return;
	}
	printAns(pre[index], index, tDis, tCost);
	cout<<index<<' ';
	if(pr != -1){
		tDis += distc[index][pr];
		tCost += cost[index][pr];
	}
}

int main(){
	ios::sync_with_stdio(false);
	fill(distc[0], distc[0]+maxv*maxv, inf);
	fill(cost[0], cost[0]+maxv*maxv, inf);
	cin>>n>>m>>s>>des;
	for(int i=0; i<m; i++){
		int u, v, di, co;
		cin>>u>>v>>di>>co;
		distc[u][v] = distc[v][u] = di;
		cost[u][v] = cost[v][u] = co;
	}
	Dijkstra(s);
	int totalDistance = 0, totalCost = 0;
	printAns(des, -1, totalDistance, totalCost);
	cout<<totalDistance<<' '<<totalCost;
}
