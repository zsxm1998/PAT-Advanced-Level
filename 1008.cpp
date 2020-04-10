#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n, ans = 0, f = 0, r;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>r;
		if(r-f > 0) ans += 6 * (r-f);
		else ans += 4 * (f-r);
		ans += 5;
		f = r;
	}
	cout<<ans;
	return 0;
}

