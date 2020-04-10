#include <bits/stdc++.h>
using namespace std;
struct record {
	string name, id;
	int grade;
	friend bool operator<(record a, record b) {
		return a.grade > b.grade;
	}
	record(string n, string i, int g) {
		name = n;
		id = i;
		grade = g;
	}
};
int main() {
	ios::sync_with_stdio(false);
	list<record> lst;
	int n;
	cin>>n;
	while(n--) {
		string name, id;
		int grade;
		cin>>name>>id>>grade;
		lst.push_back(record(name, id, grade));
	}
	lst.sort();
	int min, max;
	cin>>min>>max;
	auto it=lst.begin();
	while(it!=lst.end()) {
		if(it->grade<min || it->grade>max) {
			it = lst.erase(it);
		} else it++;
	}
	if(lst.size() > 0) {
		for(auto r : lst) {
			cout<<r.name<<' '<<r.id<<endl;
		}
	}else cout<<"NONE"<<endl;
	return 0;
}

