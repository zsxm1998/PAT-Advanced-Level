#include <bits/stdc++.h>//这个E是指天数而不是英里数 
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	sort(v.begin(), v.end(), greater<int>());
	int e = 0;
	while(e<n && v[e]>e+1) e++;
	cout<<e;
}
