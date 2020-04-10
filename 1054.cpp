#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	map<int, int> mp;
	int m, n;
	cin>>m>>n;
	int size = m * n;
	for(int i=0; i<size; i++){
		int in;
		cin>>in;
		mp[in]++;
	}
	int max = 0, maxcolor;
	for(auto it : mp){
		if(it.second > max){
			max = it.second;
			maxcolor = it.first;
		}
	}
	cout<<maxcolor;
	return 0;
}

