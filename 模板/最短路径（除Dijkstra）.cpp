#include <bits/stdc++.h>
using namespace std;

const int maxv = 200;
const int inf = 0x3fffffff;
int n, m;
struct Node{
	int v, dis;
};
vector<Node> Adj[maxv];
int d[maxv], num[maxv];
vector<int> pre[maxv];
bool Bellman_Ford(int s){
	//初始化部分 
	fill(d, d+maxv, inf);
	memset(num, 0, sizeof(num));
	d[s] = 0;
	num[s] = 1;//在这个算法num代表最短路径数 
	//求解数组d部分，循环n-1次
	for(int i=0; i<n-1; i++){
		for(int u=0; u<n; u++){
			for(int j=0; j<Adj[u].size(); j++){
				int v = Adj[u][j].v, dis = Adj[u][j].dis;
				if(d[u] + dis < d[v]){
					d[v] = d[u] + dis;
					pre[v].clear();
					pre[v].push_back(u);
					num[v] = num[u];
				}else if(d[u] + dis == d[v]){
					pre[v].push_back(u);//这句话要放在下面几句话的前面 
					num[v] = 0;//这里对于计算最短路径条数和Dijkstra不同，要清空后重新计算 
					for(int it : pre[v]){
						num[v] += num[it];
					}
				}
			}
		}
	} 
	//判断负环的部分
	for(int u=0; u<n; u++){
		for(int j=0; j<Adj[u].size(); j++){
			int v = Adj[u][j].v, dis = Adj[u][j].dis;
			if(d[u] + dis < d[v]){
				return false;
			}
		}
	}
	return true;
} 

bool inq[maxv] = {false};
bool SPFA(int s){
	//初始化部分 
	fill(d, d+maxv, inf);
	memset(num, 0, sizeof(num));
	memset(inq, false, sizeof(inq));
	//源点入队部分
	queue<int> q;
	q.push(s);
	inq[s] = true;
	num[s]++;//在这个算法中num代表节点入队次数
	d[s] = 0; 
	//主体部分 
	while(!q.empty()){
		int u = q.front();
		q.pop();
		inq[u] = false;
		for(int i=0; i<Adj[u].size(); i++){
			int v = Adj[u][i].v, dis = Adj[u][i].dis;
			if(d[u] + dis < d[v]){
				d[v] = d[u] + dis;
				if(!inq[v]){
					q.push(v);
					inq[v] = true;
					num[v]++;
					if(num[v] >= n){
						return false;//有可达负环 
					}
				}
			}
		}
	}
	return true;//无可达负环 
}

int dis[maxv][maxv];
int path[maxv][maxv];//i->j最短路径上j的前驱节点 
void Floyd(){
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(dis[i][k]!=inf && dis[k][j]!=inf && dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}
void printPath(int s, int d){
	if(path[s][d] == -1){
		cout<<"没有路径！";
		return;
	}
	if(path[s][d] == s){
		cout<<s<<' '<<d;
		return; 
	}else{
		printPath(s, path[s][d]);
		cout<<' '<<d;
		return;
	}
}

int main(){//此主函数针对Floyd算法 
	//初始化 
	fill(dis[0], dis[0]+maxv*maxv, inf);
	fill(path[0], path[0]+maxv*maxv, -1);
	cout<<"输入顶点数和边数：" ; 
	cin>>n>>m;
	for(int i=0; i<n; i++){
		dis[i][i] = 0;
		path[i][i] = i;
	} 
	//边录入 
	int u, v, w;
	for(int i=0; i<m; i++){
		cout<<"输入第"<<i+1<<"条边的起点、终点、边长："; 
		cin>>u>>v>>w;
		dis[u][v] = w;
		dis[v][u] = w;//有向图则没有这句话 
		path[u][v] = u;
		path[v][u] = v;//有向图则没有这句话 
	}
	//Floyd
	Floyd();
	while(1){
		int start, destination;
		cout<<"输入要查询路径的起点和终点（输入-1退出程序）：";
		cin>>start;
		if(start == -1){
			break;
		}
		cin>>destination;
		printPath(start, destination);
		cout<<endl;
	} 
	return 0; 
}
