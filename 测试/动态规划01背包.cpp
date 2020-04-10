#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int maxv = 1000;
int w[maxn], c[maxn], dp[maxn][maxv] = {0};
int main(){
	ios::sync_with_stdio(false);
	int n, V;
	cin>>n>>V;
	for(int i=1; i<=n; i++) cin>>w[i];
	for(int i=1; i<=n; i++) cin>>c[i];
	for(int i=1; i<=n; i++){
		for(int v=0; v<w[i]; v++) dp[i][v] = dp[i-1][v];
		for(int v=w[i]; v<=V; v++){
			dp[i][v] = max(dp[i-1][v], dp[i-1][v-w[i]]+c[i]);
		}
		for(int j=0; j<=V; j++) cout<<setw(4)<<dp[i][j]<<(j==V?'\n':' ');
	}
	int max = 0;
	for(int i=0; i<=V; i++){
		if(dp[n][i] > max){
			max = dp[n][i];
		}
	}
	cout<<max;
	return 0;
}

