#include <bits/stdc++.h>
using namespace std;
const int maxve = 10010;
int n, m;
bool hash_table[maxve];
vector<int> adj[maxve];
int main(){
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(i);
		adj[v].push_back(i);
	}
	int k;
	cin>>k;
	for(int i=0; i<k; i++){
		memset(hash_table, false, sizeof(hash_table));
		int nv;
		cin>>nv;
		for(int j=0; j<nv; j++){
			int in;
			cin>>in;
			for(auto it : adj[in]){
				hash_table[it] = true;
			}
		}
		int j;
		for(j=0; j<m && hash_table[j]; j++){}
		if(j == m){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
} 
