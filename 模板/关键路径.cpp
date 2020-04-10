#include <bits/stdc++.h>
using namespace std;

const int maxv = 1000;
int n, m;//n为节点数，m为边数 
int inDegree[maxv], ve[maxv], vl[maxv];
struct node{
	int v, len, num;//v为边终点，len为边长，num为边（活动）的编号 
	node(int vv, int ll, int nn){
		v = vv;
		len = ll;
		num = nn;
	}
};
vector<node> G[maxv];//邻接表存储的图 
stack<int> topOrder;
bool topologicalSort(){
	queue<int> q;
	for(int i=0; i<n; i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		topOrder.push(u);
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i].v, len = G[u][i].len;
			inDegree[v]--;
			if(inDegree[v] == 0){
				q.push(v);
			}
			if(ve[u] + len > ve[v]){
				ve[v] = ve[u] + len;
			}
		}
	}
	if(topOrder.size() == n) return true;
	else return false;
}
int criticalPath(){
	memset(ve, 0, sizeof(ve));//初始化数组ve 
	if(topologicalSort() == false){//拓扑排序顺便确定ve 
		return -1;//不是有向无环图，返回-1 
	}
	//fill(vl, vl+maxv, ve[n-1]);//vl数组初始化，初始值为汇点的ve值 ,算法笔记给出的语句 
	int destination = topOrder.top();//或者可以通过求ve数组中的最大值来获取汇点的编号 
	fill(vl, vl+maxv, ve[destination]);//vl数组初始化，初始值为汇点的ve值 
	while(!topOrder.empty()){//通过逆拓扑序列求数组vl 
		int u = topOrder.top();
		topOrder.pop();
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i].v, len = G[u][i].len;
			if(vl[v] - len < vl[u]){
				vl[u] = vl[v] - len;
			}
		}
	}
	//遍历邻接表所有的边，计算活动的最早开始时间e和最迟开始时间l 
	for(int u=0; u<n; u++){
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i].v, len = G[u][i].len;
			int e = ve[u], l = vl[v] - len;
			if(e == l){//e == l说明是关键活动
				cout<<u<<"->"<<v<<" : "<<G[u][i].num<<endl;
			}
		}
	}
	//return ve[n-1];//返回关键路径长度，算法笔记给出的语句 
	return ve[destination];//返回关键路径长度
}

int main(){
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u, v, len;
		cin>>u>>v>>len;
		G[u].push_back(node(v, len, i));
	}
	int length = criticalPath();
	if(length == -1){
		cout<<"不是DAG图"; 
	}else{
		cout<<"关键路径的长度是："<<length; 
	}
}
