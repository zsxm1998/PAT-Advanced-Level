#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
char str[MAXN];
int dp[MAXN][MAXN] = {0}, n, ans = 1;
int main(){
	fgets(str, MAXN, stdin);
	n = strlen(str);
	for(int i=0; i<n; i++) dp[i][i] = 1;
	for(int i=0; i<n-1; i++){
		if(str[i] == str[i+1]){
			dp[i][i+1] = 1;
			ans = 2;
		}else dp[i][i+1] = 0;
	} 
	for(int L=3; L<=n; L++){
		for(int i=0; i+L-1<n; i++){
			int j = i + L - 1;
			if(str[i] == str[j] && dp[i+1][j-1] == 1){
				dp[i][j] = 1;
				ans = L;
			}else dp[i][j] = 0;
		}
	}
	cout<<ans;
	return 0;
}

