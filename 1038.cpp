#include <bits/stdc++.h>
using namespace std;
bool cmp(const string &a, const string &b){
	return stoll(a)*(int)pow(10, b.size())+stoll(b) <  stoll(b)*(int)pow(10, a.size())+stoll(a);
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<string> seq(n);
	for(int i=0; i<n; i++){
		cin>>seq[i];
	}
	sort(seq.begin(), seq.end(), cmp);
	bool flag = true;
	for(int i=0; i<n; i++){
		if(flag){
			int num = stoi(seq[i]);
			if(num == 0) continue;
			else{
				cout<<num;
				flag = false;
			}
		}else cout<<seq[i];
	}
	if(flag) cout<<0;
	return 0;
}

