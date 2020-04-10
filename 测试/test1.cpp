#include<bits/stdc++.h>
using namespace std;
int main(){
	string a("str1"), b("str2");
	char c = 'C', d[4] = "QwQ";
	cout<<a+b<<endl<<a+c<<endl<<a+d<<endl;
	cout<<c+a<<endl<<d+a<<endl;
	a += c;
	a += d;
	cout<<a;
}
