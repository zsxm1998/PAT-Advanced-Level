#include <bits/stdc++.h>
using namespace std;
struct node{
	string key;
	int freq;
	node(string s, int f){
		key = s;
		freq = f;
	}
	friend bool operator<(const node &a, const node &b){
		return a.freq != b.freq ? a.freq > b.freq : a.key < b.key;
	}
};
int main(){
	ios::sync_with_stdio(false);
	map<string, int> mp;
	set<node> st;
	string in, word = "";
	getline(cin, in);
	transform(in.begin(), in.end(), in.begin(), ::tolower);
	for(int i=0; i<=in.size(); i++){
		if(i==in.size() || !isalnum(in[i])){
			mp[word]++;
			word = "";
		}else{
			word += in[i];
		}
	}
	for(auto it : mp){
		if(it.first != ""){
			st.insert(node(it.first, it.second));
		}
	}
	auto it = st.begin();
	cout<<it->key<<' '<<it->freq;
	return 0;
}

