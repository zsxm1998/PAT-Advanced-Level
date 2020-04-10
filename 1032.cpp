#include <bits/stdc++.h>
using namespace std;
struct node{
	char data;
	int next;
}memo[100010];
int main(){
	ios::sync_with_stdio(false);
	int s1, s2, n;
	cin>>s1>>s2>>n;
	for(int i=0; i<n; i++){
		int add, next;
		char data;
		cin>>add>>data>>next;
		memo[add].data = data;
		memo[add].next = next;
	}
	map<int, bool> mp;
	for(int i=s1; i!=-1; i=memo[i].next) mp[i] = true;
	int common = -1;
	for(int i=s2; i!=-1; i=memo[i].next){
		if(mp[i] == true){
			common = i;
			break;
		}
	}
	if(common == -1) cout<<common;
	else cout<<setfill('0')<<setw(5)<<common;
	return 0;
}

