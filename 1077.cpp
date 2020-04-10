#include <bits/stdc++.h>
using namespace std;

int main(){
	//if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	cin.get();
	vector<string> v(n);
	for(int i=0; i<n; i++){
		getline(cin, v[i]);
	} 
	string out;
	char tmp;
	int i = 0;
	bool flag = true;
	while(++i){
		for(int j=0; j<n; j++){
			int size = v[j].size();
			if(j==0 && i<=size){
				tmp = v[j][size-i];
			}else if(i<=size && v[j][size-i]==tmp){
				continue;
			}else{
				flag = false;
				break;
			}
		}
		if(flag == false) break;
		out = tmp + out;
	}
	if(out.size()) cout<<out;
	else cout<<"nai";
	return 0;
}

