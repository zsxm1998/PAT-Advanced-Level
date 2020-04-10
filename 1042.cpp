#include <bits/stdc++.h>
using namespace std;
string card[55] = {"","S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",\
                      "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",\
					  "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",\
					  "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13","J1","J2"};
int k, seq[55], tmp[55], change[55];
int main(){
	ios::sync_with_stdio(false);
	for(int i=1; i<55; i++) seq[i] = i;
	cin>>k;
	for(int i=1; i<55; i++) cin>>change[i];
	while(k--){
		for(int i=1; i<55; i++) tmp[change[i]] = seq[i];
		for(int i=1; i<55; i++) seq[i] = tmp[i];
	}
	for(int i=1; i<55; i++) cout<<(i==1?"":" ")<<card[seq[i]];
	return 0;
}

