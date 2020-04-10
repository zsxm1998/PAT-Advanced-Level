#include <bits/stdc++.h>
using namespace std;
map<string, unordered_set<string>> adj;
map<string, int> weight;
map<string, bool> vis;
int n, k, ttime, cnt, maxw, totalw;
string name1, name2, maxname;
struct head{
	string name;
	int num;
	head(string ss, int nn){
		name = ss;
		num = nn;
	}
	friend bool operator<(const head &a, const head &b){
		return a.name < b.name;
	}
};
set<head> output;
void dfs(string u){
	vis[u] = true;
	cnt++;
	totalw += weight[u];
	if(weight[u] > maxw){
		maxw = weight[u];
		maxname = u;
	}
	for(auto &v : adj[u]){
		if(!vis[v]) dfs(v);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>name1>>name2>>ttime;
		weight[name1] += ttime;
		weight[name2] += ttime;
		adj[name1].insert(name2);
		adj[name2].insert(name1);
	}
	for(auto &pr : weight){
		cnt = 0, maxw = -1, totalw = 0;
		if(!vis[pr.first]) dfs(pr.first);
		if(cnt > 2 && totalw/2 > k){//注意这里要除以2 
			output.insert(head(maxname, cnt));
		}
	}
	cout<<output.size()<<endl;
	for(auto &h : output){
		cout<<h.name<<' '<<h.num<<endl;
	}
	return 0;
}

