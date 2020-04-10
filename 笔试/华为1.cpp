#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int fac[11] = {0};
		for(int j=0; j<10; j++){
			cin>>fac[j];
		}
		int addNum = 0;
		while(fac[10] == 0){
			for(int j=9; j>=0; j--){
				if(fac[j] >= 2){
					fac[j] -= 2;
					fac[j+1] += 1;
					addNum++;
					break;
				}
			}
		}
		cout<<addNum<<endl;
	}
	return 0;
}
