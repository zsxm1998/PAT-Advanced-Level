#include <bits/stdc++.h>
using namespace std;
const int opentime = 8 * 3600;
const int closetime = 17 * 3600;
struct person{
	int artime, prtime;
	person(int a, int p){
		artime = a;
		prtime = p;
	}
};
struct window{
	int frtime = opentime;
};
vector<person> line;
vector<window> bank;
bool cmp1(const person &a, const person &b){
	return a.artime < b.artime;
}
struct cmp2{
	bool operator()(int a, int b){
		return bank[a].frtime!=bank[b].frtime?bank[a].frtime>bank[b].frtime:a>b; 
	}
};
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	bank.resize(k);
	priority_queue<int, vector<int>, cmp2> p;
	for(int i=0; i<k; i++) p.push(i);
	for(int i=0; i<n; i++){
		int a, b, c, d;
		scanf("%d:%d:%d %d", &a, &b, &c, &d);
		int e = a * 3600 + b * 60 + c;
		if(e <= closetime) line.push_back(person(e, d));
	}
	sort(line.begin(), line.end(), cmp1);
	double waittime = 0.0;
	for(int i=0; i<line.size(); i++){
		int now = p.top();
		p.pop();
		if(line[i].artime < bank[now].frtime) waittime += bank[now].frtime - line[i].artime;
		bank[now].frtime = max(line[i].artime, bank[now].frtime) + min(3600, line[i].prtime*60);
		p.push(now);
	}
	printf("%.1f", waittime / 60 / line.size());
	return 0;
}

