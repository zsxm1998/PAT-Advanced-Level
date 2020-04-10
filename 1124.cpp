#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	map<string, bool> vis;
	int m, n, s, cnt = 0;
	cin>>m>>n>>s;
	for(int i=1; i<=m; i++){
		string input;
		cin>>input;
		if(i == s){
			if(vis[input] == false){
				cout<<input<<endl;
				vis[input] = true;
				s += n;
				cnt++;
			}else{
				s++;
			}
		}
	}
	if(cnt == 0){
		cout<<"Keep going..."<<endl;
	}
} 
