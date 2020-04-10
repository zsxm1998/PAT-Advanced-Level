#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin>>n;
	vector<set<int>> st(n+1);
	for(int i=1; i<=n; i++){
		int m;
		cin>>m;
		while(m--){
			int x;
			cin>>x;
			st[i].insert(x);
		}
	}
	cin>>k;
	while(k--){
		int a, b, nc = 0, nt;
		cin>>a>>b;
		if(st[a].size() > st[b].size()){
			for(auto it=st[b].begin(); it!=st[b].end(); it++){
				auto it2 = st[a].find(*it);
				if(it2 != st[a].end()){
					nc++;
				}
			}
		}else{
			for(auto it=st[a].begin(); it!=st[a].end(); it++){
				auto it2 = st[b].find(*it);
				if(it2 != st[b].end()){
					nc++;
				}
			}
		}
		nt = st[a].size() + st[b].size() - nc;
		cout<<fixed<<setprecision(1)<<(double)nc/nt*100.0<<"%\n";
	}
	return 0;
}

