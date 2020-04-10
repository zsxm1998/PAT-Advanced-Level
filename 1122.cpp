#include <bits/stdc++.h>
using namespace std;
const int MAXV = 201;
int G[MAXV][MAXV] = {0};
bool checkSequence(const vector<int> &seq){
	unordered_set<int> s;
	s.insert(seq[0]);
	for(int i=1; i<seq.size(); i++){
		if(G[seq[i-1]][seq[i]]){
			s.insert(seq[i]);
		}else{
			return false;
		}
	}
	if(s.size() != seq.size()-1) return false;
	else return true;
}
int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n, m, k;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		G[u][v] = G[v][u] = 1;
	}
	cin>>k;
	while(k--){
		int ni;
		cin>>ni;
		vector<int> sequence(ni);
		for(int i=0; i<ni; i++){
			cin>>sequence[i];
		}
		if(ni!=n+1 || sequence[0]!=sequence[ni-1]){
			cout<<"NO\n";
			continue;
		}
		if(checkSequence(sequence)) cout<<"YES\n";
		else cout<<"NO\n";
	}
} 
