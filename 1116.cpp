#include <bits/stdc++.h>
using namespace std;
map<string, string> award;
map<string, bool> vis;
bool isPrime(int x){
	if(x < 2) return false;
	int sqr = (int)sqrt(x);
	bool flag = true;
	for(int i=2; i<=sqr; i++){
		if(x % i == 0){
			flag = false;
			break;
		}
	}
	return flag;
}
int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n, k;
	cin>>n;
	for(int i=1; i<=n; i++){
		string id;
		cin>>id;
		if(i == 1){
			award[id] = "Mystery Award";
		}else if(isPrime(i)){
			award[id] = "Minion";
		}else{
			award[id] = "Chocolate";
		}
	}
	cin>>k;
	for(int i=0; i<k; i++){
		string id;
		cin>>id;
		if(vis[id] == false){
			if(award[id] == ""){
				cout<<id<<": Are you kidding?\n";
			}else{
				cout<<id<<": "<<award[id]<<endl;
				vis[id] = true;
			}
		}else{
			cout<<id<<": Checked\n";
		}
	}
}
