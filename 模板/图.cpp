#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1000;
const int INF = 0x3fffffff;

#define linjiejuzhen 0   //�ڽӾ��� 
#define linjiebiao 1     //�ڽӱ� 

#if linjiejuzhen    //�ڽӾ��� ----------------------------------------
int n, G[MAXV][MAXV];//nΪ��������MAXVΪ��󶥵��� 
bool vis[MAXV] = {false};
bool inq[MAXV] = {false};
int d[MAXV]; //��Dijkstra��Prim�㷨�к��岻ͬ 
int pre[MAXV];

void DFS(int u, int depth){//����������ȱ��� 
	vis[u] = true;
	for(int v=0; v<n; v++){
		if(!vis[v] && G[u][v]!=INF){
			DFS(v, depth+1);
		}
	}
}

void DFSTravel(){//������ȱ��� 
	for(int u=0; u<n; u++){
		if(!vis[u]){
			DFS(u, 1);
		}
	}
}

void BFS(int u){//���ι�����ȱ��� 
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

void BFSTravel(){//������ȱ��� 
	for(int u=0; u<n; u++){
		if(!inq[u]){
			BFS(u);
		}
	}
}

void Dijkstra(int s){//�Ͻ�˹�����㷨 
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
		if(u == -1) return;//���Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ
		vis[u] = true;
		for(int v=0; v<n; v++){
			if(!vis[v] && G[u][v]!=INF && d[u]+G[u][v]<d[v]){//�Ҿ��õڶ������� G[u][v]!=INF����ʡ�� 
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

int Prim(int s){//����ķ�㷨��������С��������Ȩ֮�� 
	fill(d, d+MAXV, INF);
	d[s] = 0;
	int ans = 0;//�����С�������ı�Ȩ֮�� 
	for(int i=0; i<n; i++){
		int u = -1, min = INF;
		for(int j=0; j<n; j++){
			if(!vis[j] && d[j]<min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return -1;//���Ҳ���С��INF��d[u],��˵��ʣ�µĶ���ͼ���S����ͨ
		vis[u] = true;
		ans += d[u];//���뼯��S������С�ı߼�����С������ 
		for(int v=0; v<n; v++){
			if(!vis[v] && G[u][v]!=INF && G[u][v]<d[v]){//�Ҿ��õڶ������� G[u][v]!=INF����ʡ�� 
				d[v] = G[u][v];
			}
		}
	}
	return ans; 
}
#endif

#if linjiebiao    //�ڽӱ� ----------------------------------------
vector<int> Adj[MAXV];//MAXVΪ��󶥵��� 
int n;//nΪ������
bool vis[MAXV] = {false};
bool inq[MAXV] = {false};
struct Node{
	int v, dis;
};
vector<Node> G[MAXV];
int d[MAXV];//��Dijkstra��Prim�㷨�к��岻ͬ 
int pre[MAXV];

void DFS(int u, int depth){//����������ȱ��� 
	vis[u] = true;
	for(int i=0; i<Adj[u].size(); i++){
		int v = Adj[u][i];
		if(!vis[v]){
			DFS(v, depth+1);
		}
	}
}

void DFSTravel(){//������ȱ��� 
	for(int u=0; u<n; u++){
		if(!vis[u]){
			DFS(u, 1);
		}
	}
}

void BFS(int u){//���ι�����ȱ��� 
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

void BFSTravel(){//������ȱ��� 
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
		if(u == -1) return;//���Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ
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

int Prim(int s){//����ķ�㷨��������С��������Ȩ֮�� 
	fill(d, d+MAXV, INF);
	d[s] = 0;
	int ans = 0;//�����С�������ı�Ȩ֮�� 
	for(int i=0; i<n; i++){
		int u = -1, min = INF;
		for(int j=0; j<n; j++){
			if(!vis[j] && d[j]<min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return -1;//���Ҳ���С��INF��d[u],��˵��ʣ�µĶ���ͼ���S����ͨ
		vis[u] = true;
		ans += d[u];//���뼯��S������С�ı߼�����С������ 
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
