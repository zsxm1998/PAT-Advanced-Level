#include <bits/stdc++.h>
using namespace std;
const int opentime = 8 * 60;
const int closetime = 17 * 60;
int n, m, k, q;
struct window{
	int time = opentime;
	deque<int> q;
}; 
struct customer{
	int prtime, sttime, entime;
};
vector<window> bank;
vector<customer> cus;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k>>q;
	bank.resize(n);
	cus.resize(k+1);
	for(int i=1; i<=k; i++) cin>>cus[i].prtime;
	int i;
	for(i=1; i<=k; i++){
		int minwin = -1, minlen = m;
		for(int j=0; j<n; j++){
			if(bank[j].q.size() < minlen){
				minlen = bank[j].q.size();
				minwin = j;
			}
		}
		if(minwin == -1) break;
		bank[minwin].q.push_back(i);
	}
	for(; i<=k; i++){
		int minwin = -1, mintime = INT_MAX;
		for(int j=0; j<n; j++){
			if(bank[j].time+cus[bank[j].q.front()].prtime < mintime){
				mintime = bank[j].time + cus[bank[j].q.front()].prtime;
				minwin = j;
			}
		}
		int c = bank[minwin].q.front();
		bank[minwin].q.pop_front();
		cus[c].sttime = bank[minwin].time;
		cus[c].entime = bank[minwin].time = bank[minwin].time + cus[c].prtime;
		bank[minwin].q.push_back(i);
	}
	for(int i=0; i<n; i++){
		while(!bank[i].q.empty()){
			int c = bank[i].q.front();
			bank[i].q.pop_front();
			cus[c].sttime = bank[i].time;
			cus[c].entime = bank[i].time = bank[i].time + cus[c].prtime;
		}
	}
	cout<<setfill('0');
	for(int i=0; i<q; i++){
		int u;
		cin>>u;
		if(cus[u].sttime < closetime){
			cout<<setw(2)<<cus[u].entime/60<<':'<<setw(2)<<cus[u].entime%60<<endl;
		}else cout<<"Sorry\n";
	}
	return 0;
}

