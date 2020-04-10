#include <bits/stdc++.h>
using namespace std;
const int maxv = 501;//最开始这里写500导致最后一个测试点答案错误 
vector<int> adj[maxv];
bool vis[maxv] = {false};
int visCnt = 0;//最开始没有遍历是否是连通图导致一个测试点答案错误 
void dfs(int u){//最开始没有遍历是否是连通图导致一个测试点答案错误 
	vis[u] = true;
	visCnt++;
	for(int v : adj[u]){
		if(vis[v] == false){
			dfs(v);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int odd=0, even = 0;
	for(int i=1; i<=n; i++){
		cout<<adj[i].size()<<(i==n?'\n':' ');
		if(adj[i].size() % 2 == 0){
			even++;
		}else{
			odd++;
		}
	}
	dfs(1);//最开始没有遍历是否是连通图导致一个测试点答案错误 
	if(visCnt < n){//最开始没有遍历是否是连通图导致一个测试点答案错误 
		cout<<"Non-Eulerian";//最开始没有遍历是否是连通图导致一个测试点答案错误 
	}else if(even == n){
		cout<<"Eulerian";
	}else if(odd == 2){
		cout<<"Semi-Eulerian";
	}else{
		cout<<"Non-Eulerian";
	}
}
