#include <bits/stdc++.h>
using namespace std;
int m, n, k; 
void check(){
	vector<int> seq(n);
	for(int i=0; i<n; i++) cin>>seq[i];
	for(int i=0; i<n; i++){
		int pre = seq[i], cnt = 1;
		for(int j=i+1; j<n; j++){
			if(seq[j] < seq[i]){
				if(seq[j] < pre && cnt < m){
					pre = seq[j];
					cnt++;
				}else{
					cout<<"NO\n";
					return;
				}
			}
		}
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin>>m>>n>>k;
	while(k--){
		check();
	}
	return 0;
}

