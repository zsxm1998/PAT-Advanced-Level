#include <bits/stdc++.h>
using namespace std;

int main(){
	//if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	int n, m;
	cin>>n;
	vector<long long> v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	cin>>m;
	v.resize(n+m);
	for(int i=0; i<m; i++) cin>>v[n+i];
	sort(v.begin(), v.end());
	cout<<v[(n+m-1)/2];
	return 0;
}

