#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c;
	cin>>a>>b;
	c = a+b;
	stack<int> st;	
	while(abs(c) >= 1000){
		st.push(abs(c) % 1000);
		c /= 1000;
	}
	cout<<c;
	while(!st.empty()){
		cout<<','<<setfill('0')<<setw(3)<<st.top();
		st.pop();
	}
}
