#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	map<int, int> mp;
	int n, m;
	cin>>n>>m;
	while(n--){
		int f;
		cin>>f;
		mp[f]++;
	}
	if(m % 2 == 1){
		for(int i=0; i<=m/2; i++){
			if(mp[i] && mp[m-i]){
				cout<<i<<' '<<m-i;
				return 0;
			}
		}
	}else{
		for(int i=0; i<=m/2; i++){
			if((i==m/2 && mp[i]>=2)||(i!=m/2 && mp[i] && mp[m-i])){
				cout<<i<<' '<<m-i;
				return 0;
			}
		}
	}
	cout<<"No Solution";
	return 0;
}

