#include <bits/stdc++.h>
using namespace std;
const int maxv = 501;//�ʼ����д500�������һ�����Ե�𰸴��� 
vector<int> adj[maxv];
bool vis[maxv] = {false};
int visCnt = 0;//�ʼû�б����Ƿ�����ͨͼ����һ�����Ե�𰸴��� 
void dfs(int u){//�ʼû�б����Ƿ�����ͨͼ����һ�����Ե�𰸴��� 
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
	dfs(1);//�ʼû�б����Ƿ�����ͨͼ����һ�����Ե�𰸴��� 
	if(visCnt < n){//�ʼû�б����Ƿ�����ͨͼ����һ�����Ե�𰸴��� 
		cout<<"Non-Eulerian";//�ʼû�б����Ƿ�����ͨͼ����һ�����Ե�𰸴��� 
	}else if(even == n){
		cout<<"Eulerian";
	}else if(odd == 2){
		cout<<"Semi-Eulerian";
	}else{
		cout<<"Non-Eulerian";
	}
}
