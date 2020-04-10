#include <bits/stdc++.h>
using namespace std;
int n;
string tid, tpwd;
vector<string> oid, opwd;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>tid>>tpwd;
		bool change = false;
		for(int j=0; j<tpwd.size(); j++){
			if(tpwd[j] == '1'){
				tpwd[j] = '@';
				change = true;
			}else if(tpwd[j] == '0'){
				tpwd[j] = '%';
				change = true;
			}else if(tpwd[j] == 'l'){
				tpwd[j] = 'L';
				change = true;
			}else if(tpwd[j] == 'O'){
				tpwd[j] = 'o';
				change = true;
			}
		}
		if(change){
			oid.push_back(tid);
			opwd.push_back(tpwd);
		}
	}
	if(oid.size() == 0){
		if(n == 1){
			cout<<"There is 1 account and no account is modified";
		}else{
			cout<<"There are "<<n<<" accounts and no account is modified";
		}
	}else{
		cout<<oid.size()<<endl;
		for(int i=0; i<oid.size(); i++){
			cout<<oid[i]<<' '<<opwd[i]<<endl;
		}
	}
	return 0;
}

