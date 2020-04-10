#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int> seq(n);
	map<int, int> mp;
	for(int i=0; i<n; i++){
		cin>>seq[i];
		mp[seq[i]]++;
	}
	for(int i=0; i<n; i++){
		if(mp[seq[i]] == 1){
			cout<<seq[i];
			return 0;
		}
	}
	cout<<"None";
	return 0;
}

