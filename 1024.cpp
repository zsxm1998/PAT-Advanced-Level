#include <bits/stdc++.h>
using namespace std;
string add(string a, string b){
	string c;
	int carry = 0;
	for(int i=a.size()-1; i>=0; i--){
		int x = (a[i]-'0') + (b[i]-'0') + carry;
		c = (char)(x%10 + '0') + c;
		carry = x / 10;
	}
	if(carry > 0) c = (char)(carry + '0') + c;
	return c;
}
int main(){
	ios::sync_with_stdio(false);
	string n;
	int k;
	cin>>n>>k;
	string m = n;
	reverse(m.begin(), m.end());
	for(int i=0; i<k; i++){
		if(n == m){
			cout<<n<<'\n'<<i;
			return 0;
		}
		n = add(n, m);
		m = n;
		reverse(m.begin(), m.end());
	}
	cout<<n<<'\n'<<k;
	return 0;
}

