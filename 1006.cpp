#include <bits/stdc++.h>
using namespace std;
struct Record{
	string name;
	int intime, outtime;
};
bool cmpin(const Record &a, const Record &b){
	return a.intime < b.intime;
}
bool cmpout(const Record &a, const Record &b){
	return a.outtime > b.outtime;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<Record> r(n);
	for(int i=0; i<n; i++){
		int a, b, c, d, e, f;
		char t;
		cin>>r[i].name>>a>>t>>b>>t>>c>>d>>t>>e>>t>>f;
		r[i].intime = a*3600 + b*60 + c;
		r[i].outtime = d*3600 + e*60 + f;
	}
	sort(r.begin(), r.end(), cmpin);
	cout<<r[0].name<<' ';
	sort(r.begin(), r.end(), cmpout);
	cout<<r[0].name;
	return 0;
}

