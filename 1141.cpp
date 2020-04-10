//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct school{
	string id;
	int ns=0, rank;
	double tws = 0.0;
};

bool cmp(const school &s1, const school &s2){
	if((int)s1.tws != (int)s2.tws){
		return (int)s1.tws > (int)s2.tws;
	}
	else if(s1.ns != s2.ns){
		return s1.ns < s2.ns;
	}
	else{
		return s1.id < s2.id;
	}
}

int main(){
	ios::sync_with_stdio(false);
	map<string, school> mp;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		string id, sch;
		int score;
		cin>>id>>score>>sch;
		transform(sch.begin(), sch.end(), sch.begin(), ::tolower);//将学校代码转换成全小写 
		mp[sch].id = sch;
		mp[sch].ns += 1;
		if(id[0] == 'B'){
			mp[sch].tws += score / 1.5;
		}
		if(id[0] == 'A'){
			mp[sch].tws += score;
		}
		if(id[0] == 'T'){
			mp[sch].tws += score * 1.5;
		}
	}
	vector<school> list;
	for(auto it : mp){
		list.push_back(it.second);
	}
	sort(list.begin(), list.end(), cmp);
	int pretws = -1, prerank = 1;
	for(int i=0; i<list.size(); i++){
		if((int)list[i].tws == pretws){
			list[i].rank = prerank;
		}
		else{
			list[i].rank = prerank = i+1;
			pretws = (int)list[i].tws;
		}
	}
	cout<<list.size()<<endl;
	for(auto it : list){
		cout<<it.rank<<' '<<it.id<<' '<<(int)it.tws<<' '<<it.ns<<endl;
	} 
	return 0;
}
