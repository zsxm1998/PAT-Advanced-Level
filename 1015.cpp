#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x){
	if(x < 2) return false;
	int sqr = sqrt(x);
	for(int i=2; i<=sqr; i++){
		if(x % i == 0) return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	int n, d;
	while(cin>>n>>d){
		if(isPrime(n) == false) cout<<"No\n";
		else{
			string num;
			while(n){
				num = (char)('0'+n%d) + num;
				n /= d;
			}
			int x = 0;
			for(int i=0; i<num.size(); i++){
				x += (num[i]-'0')*(int)pow(d, i);
			}
			if(isPrime(x)) cout<<"Yes\n";
			else cout<<"No\n";
		}
	} 
	return 0;
}

