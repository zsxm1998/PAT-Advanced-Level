#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n;
int seq[MAXN] = {0}, leftmax[MAXN] = {0};
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>seq[i];
		leftmax[i] = max(leftmax[i-1], seq[i]);
	}
	stack<int> st;
	int rightmin = INT_MAX;
	for(int i=n; i>0; i--){
		rightmin = min(rightmin, seq[i]);
		if(leftmax[i]==seq[i] && rightmin==seq[i]) st.push(seq[i]);
	}
	cout<<st.size()<<endl;
	if(st.empty()) cout<<endl;//为了应付测试点2，它的答案是0 
	while(!st.empty()){
		cout<<st.top();
		st.pop();
		if(!st.empty()) cout<<' ';
	}
	return 0;
}

