#include <bits/stdc++.h>
using namespace std;
int n;
double p, r, sum = 0;
vector<vector<int>> adj;
map<int, int> amount;
void dfs(int u, double prize){
	if(adj[u].size() == 0){
		sum += prize * amount[u];
		return;
	}
	for(int i=0; i<adj[u].size(); i++){
		dfs(adj[u][i], prize * r);
	}
} 
int main(){
	//if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	cin>>n>>p>>r;
	r = 1 + r / 100;
	adj.resize(n);
	for(int i=0; i<n; i++){
		int k;
		cin>>k;
		if(k == 0) cin>>amount[i];//map能直接输入 
		else{
			adj[i].resize(k);
			for(int j=0; j<k; j++) cin>>adj[i][j];
		}
	}
	dfs(0, p);
	cout<<fixed<<setprecision(1)<<sum;
	return 0;
}

