#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		long double a, b, c;//long doubleÊÇ¹Ø¼ü 
		cin>>a>>b>>c;
		cout<<"Case #"<<i<<": ";
		if(a + b - c > 0.0) cout<<"true";
		else cout<<"false";
		if(i != n) cout<<endl;
	}
	return 0;
}

