#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int n, m, s, w[MAXN]; 
vector<int> adj[MAXN];
vector<vector<int>> paths;
vector<int>path;
void dfs(int u, int sum){
	path.push_back(w[u]);
	sum += w[u];
	if(adj[u].size() == 0){
		if(sum == s) paths.push_back(path);
		path.pop_back();
		return;
	}
	for(int i=0; i<adj[u].size(); i++){
		dfs(adj[u][i], sum);
	}
	path.pop_back();
}
bool cmp(const vector<int> &a, const vector<int> &b){
	for(int i=0; i<a.size()&&i<b.size(); i++){
		if(a[i] != b[i]) return a[i] > b[i];
	}
	/*if(i == a.size()) return true;
	else return false;*///导致最后一个测试点段错误的根源，在a<b和a==b的意义上都return了true 
	//return false;//这里return true会导致最后一个节点段错误 
	return a.size() > b.size();
	//只有意义上a<b时才能return true，若在意义上a==b时return true则会导致程序出错，这就是为什么通不过最后一个测试点的原因 
}
int main(){
	//if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	cin>>n>>m>>s;
	for(int i=0; i<n; i++) cin>>w[i];
	for(int i=0; i<m; i++){
		int id, k;
		cin>>id>>k;
		adj[id].resize(k);
		for(int j=0; j<k; j++) cin>>adj[id][j];
	} 
	dfs(0, 0);
	sort(paths.begin(), paths.end(), cmp);
	for(int i=0; i<paths.size(); i++){
		for(int j=0; j<paths[i].size(); j++){
			cout<<paths[i][j]<<(j==paths[i].size()-1?'\n':' ');
		}
	}
	return 0;
}

