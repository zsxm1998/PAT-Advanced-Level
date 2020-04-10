#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	string input;
	cin>>input;
	int N = input.size() + 2;
	int n1 = N/3, n2 = N/3+N%3;
	char output[n1][n2];
	fill(output[0], output[0]+n1*n2, ' ');
	int t=0;
	for(int i=0; i<n1-1; i++){
		output[i][0] = input[t++];
	}
	for(int i=0; i<n2; i++){
		output[n1-1][i] = input[t++];
	}
	for(int i=n1-2; i>=0; i--){
		output[i][n2-1] = input[t++];
	}
	for(int i=0; i<n1; i++){
		for(int j=0; j<n2; j++){
			cout<<output[i][j];
		}
		cout<<endl;
	}
	return 0;
}

