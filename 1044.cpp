#include <bits/stdc++.h>
using namespace std;
int n, m, sum[100010] = {0}, in, minsub = INT_MAX;
vector<pair<int, int>> ans;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>in;
		sum[i] = sum[i-1] + in;
	}
	for(int i=1; i<=n; i++){
		int left = i, right = n, mid;
		while(left < right){
			mid = (left + right) / 2;
			if(sum[mid] - sum[i-1] >= m) right = mid;
			else left = mid + 1;
		}
		int sub = sum[left] - sum[i-1] - m;
		if(sub >= 0 && sub < minsub){//注意限制sub>=0 
			minsub = sum[left]-sum[i-1]-m;
			ans.clear();
			ans.push_back(make_pair(i, left));
		}else if(sub >= 0 && sub == minsub){//注意限制sub>=0 
			ans.push_back(make_pair(i, left));
		}
	}
	for(auto &pa : ans){
		cout<<pa.first<<'-'<<pa.second<<endl;
	}
	return 0;
}

