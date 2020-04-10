#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int num = 0;
	map<char, int> mp;
	string shop, eva;
	cin>>shop>>eva;
	for(int i=0; i<shop.size(); i++) mp[shop[i]]++;
	for(int i=0; i<eva.size(); i++){
		if(mp[eva[i]] > 0) mp[eva[i]]--;
		else num++;
	}
	if(num > 0){
		cout<<"No "<<num;
	}else{
		for(auto it : mp){
			num += it.second;
		}
		cout<<"Yes "<<num;
	}
	return 0;
}

