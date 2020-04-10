#include <bits/stdc++.h>
using namespace std;
struct record{
	string platenum;
	int time, flag;
	record(){time = 0;}
	record(string p, int t, int f){
		platenum = p;
		time = t;
		flag = f;
	}
};
bool bynum(const record &a, const record &b){
	return a.platenum != b.platenum ? a.platenum < b.platenum : a.time < b.time;
}
bool bytimeasc(const record &a, const record &b){
	return a.time != b.time ? a.time < b.time : a.platenum < b.platenum;
}
struct bytimedesc{
	bool operator()(const record &a, const record &b){
		return a.time != b.time ? a.time < b.time : a.platenum > b.platenum;
	}
};
int t2i(int hour, int minute, int second){
	return hour*3600 + minute*60 + second;
}
void i2t(int &hour, int &minute, int &second, int time){
	hour = time / 3600;
	time = time % 3600;
	minute = time / 60;
	second = time % 60;
}
int f2i(string flag){
	if(flag == "in") return 1;
	else return -1;
}
int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n, k, pre = 0;
	cin>>n>>k;
	vector<record> input, timeorder;
	for(int i=0; i<n; i++){
		string pnum, flg;
		int h, m, s;
		char t;
		cin>>pnum>>h>>t>>m>>t>>s>>flg;
		input.push_back(record(pnum, t2i(h, m, s), f2i(flg)));
	}
	sort(input.begin(), input.end(), bynum);
	map<string, record> mp;
	for(int i=1; i<input.size(); i++){
		if(input[i].platenum==input[pre].platenum && input[i].flag<0 && input[pre].flag>0){
			timeorder.push_back(input[pre]);
			timeorder.push_back(input[i]);
			mp[input[i].platenum].platenum = input[i].platenum;
			mp[input[i].platenum].time += input[i].time - input[pre].time;
			pre = ++i;
		}else{
			pre = i;
		}
	}
	sort(timeorder.begin(), timeorder.end(), bytimeasc);
	int carnum = 0, idx = 0, tsize = timeorder.size();
	for(int i=0; i<k; i++){
		int h, m, s, nowtime;
		char t;
		cin>>h>>t>>m>>t>>s;
		nowtime = t2i(h, m, s);
		while(idx<tsize && timeorder[idx].time<=nowtime) carnum += timeorder[idx++].flag;
		cout<<carnum<<endl;
	}
	priority_queue<record, vector<record>, bytimedesc> heap;
	for(auto it : mp){
		heap.push(it.second);
	}
	int maxtime = heap.top().time, h, m, s;
	while(!heap.empty() && heap.top().time == maxtime){
		cout<<heap.top().platenum<<' ';
		heap.pop();
	}
	i2t(h, m, s, maxtime);
	cout<<setfill('0')<<setw(2)<<h<<':'<<setw(2)<<m<<':'<<setw(2)<<s;
	return 0;
}

