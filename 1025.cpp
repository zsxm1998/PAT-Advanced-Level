#include <bits/stdc++.h>
using namespace std;
struct person{
	long long id;
	int lnum, lrank, score;
	friend bool operator<(const person &a, const person &b){
		return a.score != b.score ? a.score > b.score : a.id < b.id;
	}
};
int main(){
	//if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	vector<person> per;
	int n, cnt = 0;
	cin>>n;
	for(int i=1; i<=n; i++){
		int k;
		cin>>k;
		per.resize(cnt + k);
		for(int j=0; j<k; j++){
			cin>>per[cnt+j].id>>per[cnt+j].score;
			per[cnt+j].lnum = i;
		}
		sort(per.begin()+cnt, per.end());
		int preRank = 1, preScore = per[cnt].score;
		for(int j=0; j<k; j++){
			if(per[cnt+j].score == preScore) per[cnt+j].lrank = preRank;
			else{
				preRank = per[cnt+j].lrank = j + 1;
				preScore = per[cnt+j].score;
			} 
		}
		cnt += k;
	}
	sort(per.begin(), per.end());
	cout<<setfill('0')<<cnt<<endl;
	int preRank, preScore = INT_MAX;
	for(int i=0; i<cnt; i++){
		cout<<setw(13)<<per[i].id<<' ';
		if(per[i].score == preScore) cout<<preRank<<' ';
		else{
			cout<<i+1<<' ';
			preRank = i+1;
			preScore = per[i].score;
		}
		cout<<per[i].lnum<<' '<<per[i].lrank<<endl;
	}
	return 0;
}

