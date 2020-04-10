#include <bits/stdc++.h>
using namespace std;
int dis[100010], tdis = 0, n, m, s, e, d; 
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>dis[i];
		tdis += dis[i];
	}
	cin>>m;
	while(m--){
		cin>>s>>e;
		if(s > e) swap(s, e);
		d = 0;
		for(int i=s; i<e; i++){
			d += dis[i];
		}
		cout<<(tdis-d<d?tdis-d:d)<<endl;
	}
	return 0;
}

