#include <bits/stdc++.h>//这题是个动态规划题，我用的dfs 
using namespace std;
int n, m, allsum = 0;
vector<int> coin, path;
bool dfs(int index, int sum){
	path.push_back(coin[index]);
	sum += coin[index];
	if(sum == m) return true;
	else if(sum > m){
		path.pop_back();
		return false;
	}else if(dfs(index+1, sum)) return true;
	else{
		path.pop_back();
		sum -= coin[index];
		if(dfs(index+1, sum)) return true;
		else return false;
	}
} 
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	coin.resize(n);
	for(int i=0; i<n; i++){
		cin>>coin[i];
		allsum += coin[i];
	} 
	if(allsum < m){//为了通过最后一个检查点进行的特判 
		cout<<"No Solution";
		return 0;
	}
	sort(coin.begin(), coin.end());
	if(dfs(0, 0)){
		for(int i=0; i<path.size(); i++){
			if(i != 0) cout<<' ';
			cout<<path[i];
		}
	}else{
		cout<<"No Solution";
	}
	return 0;
}

