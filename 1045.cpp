#include <bits/stdc++.h>
using namespace std;
int have[201] = {0}, cidx[201], stri[10001], dp[10001], n, m, l, incolor, ans = 1;
bool cmp(int a, int b){
	return cidx[a] <= cidx[b];
}
int main(){
	ios::sync_with_stdio(false);
	fill(dp, dp+10001, 1);
	cin>>n>>m;
	for(int i=0; i<m; i++){
		cin>>incolor;
		have[incolor] = 1;
		cidx[incolor] = i;
	}
	cin>>l;
	for(int i=0; i<l; i++){
		cin>>stri[i];
	}
	for(int i=1; i<l; i++){
		if(have[stri[i]] == 0) continue;
		for(int j=0; j<i; j++){
			if(have[stri[j]] && cidx[stri[j]]<=cidx[stri[i]] && dp[j]+1>dp[i]){
				dp[i] = dp[j] + 1;
			}
		}
		if(dp[i] > ans) ans = dp[i];
	}
	cout<<ans;
	return 0;
}

