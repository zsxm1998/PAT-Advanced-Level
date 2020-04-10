#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1000;
const int INF = 0x3fffffff;

#define linjiejuzhen 0   //邻接矩阵 
#define linjiebiao 1     //邻接表 

#if linjiejuzhen    //邻接矩阵 ----------------------------------------
int n, G[MAXV][MAXV];//n为顶点数，MAXV为最大顶点数 
bool vis[MAXV] = {false};
bool inq[MAXV] = {false};
int d[MAXV]; //在Dijkstra和Prim算法中含义不同 
int pre[MAXV];

void DFS(int u, int depth){//单次深度优先遍历 
	vis[u] = true;
	for(int v=0; v<n; v++){
		if(!vis[v] && G[u][v]!=INF){
			DFS(v, depth+1);
		}
	}
}

void DFSTravel(){//深度优先遍历 
	for(int u=0; u<n; u++){
		if(!vis[u]){
			DFS(u, 1);
		}
	}
}

void BFS(int u){//单次广度优先遍历 
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v=0; v<n; v++){
			if(!inq[v] && G[u][v] != INF){
				q.push(v);
				inq[v] = true;
			}
		}
	}
}

void BFSTravel(){//广度优先遍历 
	for(int u=0; u<n; u++){
		if(!inq[u]){
			BFS(u);
		}
	}
}

void Dijkstra(int s){//迪杰斯特拉算法 
	fill(d, d+MAXV, INF);
	for(int i=0; i<n; i++) pre[i] = i;
	d[s] = 0;
	for(int i=0; i<n; i++){
		int u = -1, min = INF;
		for(int j=0; j<n; j++){
			if(!vis[j] && d[j]<min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;//若找不到小于INF的d[u]则说明剩下的顶点和起点s不连通
		vis[u] = true;
		for(int v=0; v<n; v++){
			if(!vis[v] && G[u][v]!=INF && d[u]+G[u][v]<d[v]){//我觉得第二个条件 G[u][v]!=INF可以省略 
				d[v] = d[u] + G[u][v];
				pre[v] = u;
			}
		}
	}
}

void printPath(int s, int v){
	if(s == v){
		printf("%d\n", s);
		return;
	}
	printPath(s, pre[v]);
	printf("%d\n", v);
}

int Prim(int s){//普里姆算法，返回最小生成树边权之和 
	fill(d, d+MAXV, INF);
	d[s] = 0;
	int ans = 0;//存放最小生成树的边权之和 
	for(int i=0; i<n; i++){
		int u = -1, min = INF;
		for(int j=0; j<n; j++){
			if(!vis[j] && d[j]<min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return -1;//若找不到小于INF的d[u],则说明剩下的顶点和集合S不连通
		vis[u] = true;
		ans += d[u];//将与集合S距离最小的边加入最小生成树 
		for(int v=0; v<n; v++){
			if(!vis[v] && G[u][v]!=INF && G[u][v]<d[v]){//我觉得第二个条件 G[u][v]!=INF可以省略 
				d[v] = G[u][v];
			}
		}
	}
	return ans; 
}
#endif

#if linjiebiao    //邻接表 ----------------------------------------
vector<int> Adj[MAXV];//MAXV为最大顶点数 
int n;//n为顶点数
bool vis[MAXV] = {false};
bool inq[MAXV] = {false};
struct Node{
	int v, dis;
};
vector<Node> G[MAXV];
int d[MAXV];//在Dijkstra和Prim算法中含义不同 
int pre[MAXV];

void DFS(int u, int depth){//单次深度优先遍历 
	vis[u] = true;
	for(int i=0; i<Adj[u].size(); i++){
		int v = Adj[u][i];
		if(!vis[v]){
			DFS(v, depth+1);
		}
	}
}

void DFSTravel(){//深度优先遍历 
	for(int u=0; u<n; u++){
		if(!vis[u]){
			DFS(u, 1);
		}
	}
}

void BFS(int u){//单次广度优先遍历 
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0; i<Adj[u].size(); i++){
			int v = Adj[u][i];
			if(!inq[v]){
				q.push(v);
				inq[v] = true;
			}
		}
	}
}

void BFSTravel(){//广度优先遍历 
	for(int u=0; u<n; u++){
		if(!inq[u]){
			BFS(u);
		}
	}
}

void Dijkstra(int s){
	fill(d, d+MAXV, INF);
	for(int i=0; i<n; i++) pre[i] = i;
	d[s] = 0;
	for(int i=0; i<n; i++){
		int u = -1, min = INF;
		for(int j=0; j<n; j++){
			if(!vis[j] && d[j]<min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;//若找不到小于INF的d[u]则说明剩下的顶点和起点s不连通
		vis[u] = true;
		for(int j=0; j<G[u].size(); j++){
			int v = G[u][j].v;
			if(!vis[v] && d[u]+G[u][j].dis<d[v]){
				d[v] = d[u] + G[u][j].dis;
				pre[v] = u;
			}
		}
	}
}

void printPath(int s, int v){
	if(s == v){
		printf("%d\n", s);
		return;
	}
	printPath(s, pre[v]);
	printf("%d\n", v);
}

int Prim(int s){//普里姆算法，返回最小生成树边权之和 
	fill(d, d+MAXV, INF);
	d[s] = 0;
	int ans = 0;//存放最小生成树的边权之和 
	for(int i=0; i<n; i++){
		int u = -1, min = INF;
		for(int j=0; j<n; j++){
			if(!vis[j] && d[j]<min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return -1;//若找不到小于INF的d[u],则说明剩下的顶点和集合S不连通
		vis[u] = true;
		ans += d[u];//将与集合S距离最小的边加入最小生成树 
		for(int j=0; j<G[u].size(); j++){
			int v = G[u][j].v;
			if(!vis[v] && G[u][j].dis<d[v]){
				d[v] = G[u][j].dis;
			}
		}
	}
	return ans; 
}
#endif

int main(){
	return 0;
}
