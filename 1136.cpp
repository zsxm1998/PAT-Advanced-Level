#include <bits/stdc++.h>
using namespace std;

string add(const string &a, const string &b){
	int aLen = a.size()-1, bLen = b.size()-1, carry = 0;
	string c;
	for(;aLen>=0 && bLen>=0;aLen--, bLen--){
		char ch = (a[aLen]-'0') + (b[bLen]-'0') + carry;
		if(ch > 9){
			carry = 1;
			ch -= 10;
		}else{
			carry = 0;
		}
		c += '0'+ch;
	}
	while(aLen>=0){
		char ch = (a[aLen--]-'0') + carry;
		if(ch > 9){
			carry = 1;
			ch -= 10;
		}else{
			carry = 0;
		}
		c += '0'+ch;
	}
	while(bLen>=0){
		char ch = (b[bLen--]-'0') + carry;
		if(ch > 9){
			carry = 1;
			ch -= 10;
		}else{
			carry = 0;
		}
		c += '0'+ch;
	}
	if(carry == 1){
		c += '0'+carry;
	}
	reverse(c.begin(), c.end());
	return c;
}

int main(){
    string a, b, c;
    cin>>a;
    b = a;
    reverse(b.begin(), b.end());
    int cnt = 0;
    while(cnt < 10 && a != b){
    	cout<<a<<" + "<<b;
		a = add(a, b);
		cout<<" = "<<a<<endl;
		b = a;
		reverse(b.begin(), b.end());
		cnt++;
	}
	if(cnt < 10){
		cout<<a<<" is a palindromic number.";
	}else{
		cout<<"Not found in 10 iterations.";
	}
}
