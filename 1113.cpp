#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int> v(n); 
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	int half = n/2, sa = 0, sb = 0;
	for(int i=0; i<n; i++){
		if(i < half){
			sa += v[i];	
		}else{
			sb += v[i];	
		}
	}
	//cout<<n%2<<' '<<max(abs(sb-sa), abs((sb-v[half]) - (sa+v[half])));
	cout<<n%2<<' '<<sb-sa;
	return 0;
}

