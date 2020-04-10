#include <bits/stdc++.h>
using namespace std;
struct applicant{
	int id;
	double ge, gi, gf;
	applicant(){id=ge=gi=gf=-1;}
	applicant(int idd, double e, double i){
		id = idd;
		ge = e;
		gi = i;
		gf = (ge + gi) / 2;
	}
	friend bool operator==(const applicant &a, const applicant &b){
		return (a.ge==b.ge && a.gi==b.gi);
	}
};
bool cmp(const applicant &a, const applicant &b){
	if(a.gf != b.gf) return a.gf > b.gf;
	else if(a.ge != b.ge) return a.ge > b.ge;
	else return a.id < b.id;
}
int n, m, k;
vector<set<int>> school;
vector<applicant> schBack;
vector<int> quota;
vector<applicant> apply;
vector<vector<int>> choice;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	apply.resize(n);
	choice.resize(n, vector<int>(k));
	school.resize(m);
	schBack.resize(m);
	quota.resize(m);
	for(int i=0; i<m; i++){
		cin>>quota[i];
	}
	for(int i=0; i<n; i++){
		double ge, gi;
		cin>>ge>>gi;
		apply[i] = applicant(i, ge, gi);
		for(int j=0; j<k; j++){
			cin>>choice[i][j];
		}
	}
	sort(apply.begin(), apply.end(), cmp);
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			int cho = choice[apply[i].id][j];//这里不要写成choice[i][j],因为choice和apply已经错位了 
			if(school[cho].size()<quota[cho] || schBack[cho]==apply[i]){
				school[cho].insert(apply[i].id);
				schBack[cho] = apply[i];
				break;
			}
		}
	}
	for(int i=0; i<m; i++){
		for(auto it=school[i].begin(); it!=school[i].end(); it++){
			if(it != school[i].begin()) cout<<' ';
			cout<<*it;
		}
		cout<<endl;
	}
	return 0;
}
