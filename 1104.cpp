#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	double sum = 0.0, temp;
	for(int i=0; i<n; i++){
		cin>>temp;
		sum = sum + temp * (i+1) * (n-i);
	}
	cout<<fixed<<setprecision(2)<<sum;
	return 0;
}

