#include <bits/stdc++.h>
#include <climits>
using namespace std;
vector<vector<int>> tree;
double cheapest = numeric_limits<double>::max(), start, incre;
int cnt = 0, n;
void dfs(int u, double price){
	int size = tree[u].size();
	if(size == 0){
		if(price < cheapest){
			cheapest = price;
			cnt = 1;
		}else if(price == cheapest) cnt++;
		return;
	}
	for(int i=0; i<size; i++){
		dfs(tree[u][i], price * incre);
	}
}
int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin>>n>>start>>incre;
	incre = 1.0 + incre / 100.0;
	tree.resize(n);
	for(int i=0; i<n; i++){
		int k;
		cin>>k;
		while(k--){
			int temp;
			cin>>temp;
			tree[i].push_back(temp);
		}
	}
	dfs(0, start);
	cout<<fixed<<setprecision(4)<<cheapest<<' '<<cnt;
	return 0;
}

