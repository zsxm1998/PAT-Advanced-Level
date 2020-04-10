#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n, b;
	cin>>n>>b;
	if(n == 0){
		cout<<"Yes\n0";
		return 0;
	}
	vector<int> out;
	while(n){
		int x = n % b;
		out.push_back(x);
		n /= b;
	}
	int i = 0, j = out.size()-1;
	bool flag = true;
	while(i < j){
		if(out[i] != out[j]){
			flag = false;
			break;
		}
		i++;
		j--;
	}
	cout<<(flag?"Yes\n":"No\n");
	for(int i=out.size()-1; i>=0; i--){
		cout<<out[i];
		if(i != 0) cout<<' ';
	}
	return 0;
}

