#include <bits/stdc++.h>
using namespace std;

int main(){
	stringstream ss;
	string in;
	cin>>in;
	cout<<setfill('0');
	ss<<setfill('0');
	int start = stoi(in);
	ss<<setw(4)<<start;
	ss>>in;
	do{
		sort(in.begin(), in.end(), greater<char>());
		int a = stoi(in);
		sort(in.begin(), in.end(), less<char>());
		int b = stoi(in);
		int c = a - b;
		cout<<setw(4)<<a<<" - "<<setw(4)<<b<<" = "<<setw(4)<<c<<endl;
		ss.clear();
		ss<<setw(4)<<c;
		ss>>in;
	}while(in != "0000" && in != "6174");
	return 0;
}

