#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
double highest = -1.0, start, incre;
int n, cnt, root; 
void dfs(int u, double price){
	int size = tree[u].size();
	if(size == 0){
		if(price > highest){
			highest = price;
			cnt = 1;
		}else if(price == highest) cnt++;
		return;
	}
	for(int i=0; i<size; i++){
		dfs(tree[u][i], price * incre);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>start>>incre;
	incre = 1.0 + incre / 100.0;
	tree.resize(n);
	for(int i=0; i<n; i++){
		int father;
		cin>>father;
		if(father == -1) root = i;
		else tree[father].push_back(i);
	}
	dfs(root, start);
	cout<<fixed<<setprecision(2)<<highest<<' '<<cnt;
	return 0;
}

