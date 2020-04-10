#include <bits/stdc++.h>
using namespace std;
struct student{
	int id, grade;
	string name;
};
bool cmp1(const student &a, const student &b){
	return a.id < b.id;
}
bool cmp2(const student &a, const student &b){
	return a.name!=b.name?a.name<b.name:a.id<b.id;
}
bool cmp3(const student &a, const student &b){
	return a.grade!=b.grade?a.grade<b.grade:a.id<b.id;
}
int main(){
	ios::sync_with_stdio(false);
	int n, c;
	cin>>n>>c;
	vector<student> v(n);
	for(int i=0; i<n; i++) cin>>v[i].id>>v[i].name>>v[i].grade;
	if(c == 1){
		sort(v.begin(), v.end(), cmp1);
	}else if(c == 2){
		sort(v.begin(), v.end(), cmp2);
	}else if(c == 3){
		sort(v.begin(), v.end(), cmp3);
	}
	cout<<setfill('0');
	for(auto &st : v){
		cout<<setw(6)<<st.id<<' '<<st.name<<' '<<st.grade<<endl;
	}
	return 0;
}

