#include <bits/stdc++.h>
using namespace std;
string multiply(string a){
	string b;
	int carry = 0;
	for(int i=a.size()-1; i>=0; i--){
		int x = (a[i]-'0') * 2 + carry;
		b = (char)(x % 10 + '0') + b;
		carry = x / 10;
	}
	if(carry > 0) b = (char)(carry + '0') + b;
	return b;
}
int main(){
	ios::sync_with_stdio(false);
	string instr;
	cin>>instr;
	string doustr = multiply(instr);
	map<char, int> mp1, mp2;
	for(int i=0; i<instr.size(); i++) mp1[instr[i]]++;
	for(int i=0; i<doustr.size(); i++) mp2[doustr[i]]++;
	if(mp1 == mp2) cout<<"Yes\n";
	else cout<<"No\n";
	cout<<doustr;
	return 0;
}

