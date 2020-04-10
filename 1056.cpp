#include <bits/stdc++.h>
using namespace std;
struct person{
	int id, w, order, rank;
}; 
bool cmpById(const person &a, const person &b){
	return a.id < b.id;
}
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	vector<person> in(n), v(n);
	vector<int> turn(n);
	for(int i=0; i<n; i++){
		turn[i] = i;
		in[i].id = i;
		cin>>in[i].w;
	} 
	for(int i=0; i<n; i++){
		int order;
		cin>>order;
		v[i] = in[order];
	} 
	while(turn.size() != 1){
		vector<int> winner;
		int rank = ceil(turn.size()/(double)m) + 1;
		for(int i=0; i<turn.size(); i+=m){
			int maxw = v[turn[i]].w, maxid = turn[i];
			for(int j=i; j<turn.size() && j-i<m; j++){
				if(v[turn[j]].w > maxw){
					maxw = v[turn[j]].w;
					maxid = turn[j];
				}
				v[turn[j]].rank = rank;
			}
			winner.push_back(maxid);
		}
		turn = winner;
	}
	v[turn[0]].rank = 1;
	sort(v.begin(), v.end(), cmpById);
	for(int i=0; i<n; i++){
		cout<<(i==0?"":" ")<<v[i].rank;
	}
	return 0;
}

