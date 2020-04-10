#include <bits/stdc++.h>
using namespace std;
struct node{
	int u, level;
	node(int uu, int ll){
		u = uu;
		level = ll;
	}
};
vector<int> adj[1001];
int n, l;
bool inq[1001] = {false};
int bfs(int root){
	int cnt = -1;//这里cnt不能为0，因为root本身不算一个转发者 
	queue<node> q;
	q.push(node(root, 0));//root是第0层 
	inq[root] = true;
	while(!q.empty()){
		node nd = q.front();
		q.pop();
		cnt++;
		int u = nd.u, level = nd.level;
		if(level < l){
			for(int i=0; i<adj[u].size(); i++){
				int v = adj[u][i];
				if(inq[v] == false){
					q.push(node(v, level+1));
					inq[v] = true;
				}
			}
		}
	}
	return cnt;
}
int main(){
	//if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	cin>>n>>l;
	for(int i=1; i<=n; i++){
		int m;
		cin>>m;
		while(m--){
			int u;
			cin>>u;
			adj[u].push_back(i);
		}
	}
	int k;
	cin>>k;
	while(k--){
		//memset(inq, false, sizeof(inq));
		fill(inq, inq+1001, false);
		int u;
		cin>>u;
		cout<<bfs(u)<<endl;
	}
	return 0;
}

