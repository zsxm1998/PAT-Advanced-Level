#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	string ori, type, out;
	cin>>ori>>type;
	transform(ori.begin(), ori.end(), ori.begin(), ::toupper);
	transform(type.begin(), type.end(), type.begin(), ::toupper);
	map<char, bool> mp;
	int i=0, j=0;
	while(j < type.size()){
		if(ori[i] != type[j]){
			if(mp[ori[i]] == false){
				mp[ori[i]] = true;
				out += ori[i];
			}
			i++;
		}else{
			i++;
			j++;
		}
	}
	while(i < ori.size()){
		if(mp[ori[i]] == false){
			mp[ori[i]] = true;
			out += ori[i];
		}
		i++;
	}
	cout<<out;
	return 0;
}

