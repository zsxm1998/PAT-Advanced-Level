#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100];
int have[100] = {0};
int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u, k;
		cin>>u>>k;
		adj[u].resize(k);
		for(int j=0; j<k; j++){
			cin>>adj[u][j];
			have[adj[u][j]]++;
		}
	}
	int root = 1, thisnum = 1, nextnum = 0, level = 1, maxlevel = 1, maxnum = 1;
	while(have[root]) root++;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		thisnum--;
		nextnum += adj[u].size();
		for(int i=0; i<adj[u].size(); i++) q.push(adj[u][i]);
		if(thisnum == 0){
			if(nextnum > maxnum){
				maxnum = nextnum;
				maxlevel = level + 1;
			}
			thisnum = nextnum;
			nextnum = 0;
			level++;
		}
	}
	cout<<maxnum<<' '<<maxlevel;
	return 0;
}

