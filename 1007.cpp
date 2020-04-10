#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10001;
int seq[MAXN], dpsum[MAXN] = {-0x3fffffff}, dpi[MAXN] , n;
int main(){
	ios::sync_with_stdio(false);
	bool positiveFlag = false;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>seq[i];
		if(seq[i] >= 0) positiveFlag = true;
		if(dpsum[i-1]+seq[i] < seq[i]){
			dpsum[i] = seq[i];
			dpi[i] = i;
		}else{
			dpsum[i] = dpsum[i-1] + seq[i];
			dpi[i] = dpi[i-1];
		}
	}
	int maxsum = INT_MIN, maxidx = 1;
	for(int i=1; i<=n; i++){
		if(dpsum[i] > maxsum){
			maxsum = dpsum[i];
			maxidx = i;
		}
	}
	if(positiveFlag == false){
		cout<<0<<' '<<seq[1]<<' '<<seq[n];
	}else{
		cout<<maxsum<<' '<<seq[dpi[maxidx]]<<' '<<seq[maxidx];
	}
	return 0;
}

