#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		string input;
		cin>>input;
		string astr = input.substr(0, input.size()/2);
		string bstr = input.substr(input.size()/2);
		int a = stoi(astr);
		int b = stoi(bstr);
		int c = stoi(input);
		if(a*b!=0 && c%(a*b) == 0){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
} 
