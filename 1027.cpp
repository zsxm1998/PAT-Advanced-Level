#include <bits/stdc++.h>
using namespace std;
void printDigit(int x){
	if(x <= 9) cout<<x;
	else cout<<(char)(x-10+'A');
}
void printColor(int x){
	int u = x / 13, v = x % 13;
	printDigit(u);
	printDigit(v);
}
int main(){
	ios::sync_with_stdio(false);
	int a, b, c;
	cin>>a>>b>>c;
	cout<<'#';
	printColor(a);
	printColor(b);
	printColor(c);
	return 0;
}

