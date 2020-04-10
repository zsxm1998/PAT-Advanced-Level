#include <bits/stdc++.h>
using namespace std;
int n, k, idx, snum;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	map<string, set<int>> mp;
	string stu;
	for(int i=0; i<k; i++){
		cin>>idx>>snum;
		while(snum--){
			cin>>stu;
			mp[stu].insert(idx);
		}
	}
	for(int i=0; i<n; i++){
		cin>>stu;
		cout<<stu<<' '<<mp[stu].size();
		for(auto cn : mp[stu]) cout<<' '<<cn;
		cout<<endl;
	}
	return 0;
}

