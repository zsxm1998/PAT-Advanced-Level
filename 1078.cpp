#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x){
	if(x < 2) return false;
	int sqr = (int)sqrt(x);
	for(int i=2; i<=sqr; i++){
		if(x % i == 0) return false;
	}
	return true;
}
int main(){
	//if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	int m, n;
	cin>>m>>n;
	while(!isPrime(m)) m++;
	vector<int> hashTable(m, 0), in(n);
	map<int, int> pos;
	for(int i=0; i<n; i++){
		bool insertFlag = false;
		int h;
		cin>>in[i];
		h = in[i] % m;
		for(int j=0; j<=m/2; j++){
			int p = (h + j * j) % m;
			if(hashTable[p] == 0){
				hashTable[p] = in[i];
				pos[in[i]] = p;
				insertFlag = true;
				break;
			}
		}
		if(insertFlag == false) pos[in[i]] = -1;
	}
	for(int i=0; i<n; i++){
		if(i != 0) cout<<' ';
		if(pos[in[i]] != -1) cout<<pos[in[i]];
		else cout<<'-';
	}
	return 0;
}

