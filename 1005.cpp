#include <bits/stdc++.h>
using namespace std;
string digit[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
	ios::sync_with_stdio(false);
	string instr, outstr;
	cin>>instr;
	long long sum = 0;
	for(int i=0; i<instr.size(); i++){
		sum += instr[i] - '0';
	}
	outstr = to_string(sum);
	for(int i=0; i<outstr.size(); i++){
		if(i != 0) cout<<' ';
		cout<<digit[outstr[i]-'0'];
	}
	return 0;
}

