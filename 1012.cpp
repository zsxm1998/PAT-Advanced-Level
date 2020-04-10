#include <bits/stdc++.h>
using namespace std;
struct student{
	int id, score[4];
	student(int u, int v, int w, int x){
		id = u;
		score[1] = v;
		score[2] = w;
		score[3] = x;
		score[0] = (v+w+x)/3;
	}
};
vector<student> rk;
map<int, int> ranknum;
map<int, char> ranktype;
char type[4] = {'A', 'C','M','E'};
bool cmp0(const student &a, const student &b){
	return a.score[0] > b.score[0];
}
bool cmp1(const student &a, const student &b){
	return a.score[1] > b.score[1];
}
bool cmp2(const student &a, const student &b){
	return a.score[2] > b.score[2];
}
bool cmp3(const student &a, const student &b){
	return a.score[3] > b.score[3];
}
bool (*cmp[4])(const student &a, const student &b) = {cmp0, cmp1, cmp2, &cmp3};//取不取地址都一样 
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int id, c, m, e;
		cin>>id>>c>>m>>e;
		rk.push_back(student(id, c, m, e));
	}
	for(int i=0; i<4; i++){
		sort(rk.begin(), rk.end(), cmp[i]);
		int prescore = -1, prerank;
		for(int j=0; j<n; j++){
			int nowrank;
			if(rk[j].score[i] == prescore) nowrank = prerank;
			else{
				nowrank = prerank = j + 1;
				prescore = rk[j].score[i];
			}
			if(i == 0 || nowrank < ranknum[rk[j].id]){
				ranknum[rk[j].id] = nowrank;
				ranktype[rk[j].id] = type[i];
			}
		}
	}
	for(int i=0; i<m; i++){
		int id;
		cin>>id;
		if(ranknum[id] == 0) cout<<"N/A\n";
		else cout<<ranknum[id]<<' '<<ranktype[id]<<endl;
	}
	return 0;
}

