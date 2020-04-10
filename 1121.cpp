#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<pair<int, int>> vec(n);
	for(int i=0; i<n; i++){
		int a, b;
		cin>>a>>b;
		vec[i] = pair<int, int>(a, b);
	}
	set<int> present;
	int m;
	cin>>m;
	for(int i=0; i<m; i++){
		int a;
		cin>>a;
		present.insert(a);
	}
	for(int i=0; i<n; i++){
		auto it1 = present.find(vec[i].first);
		auto it2 = present.find(vec[i].second);
		if(it1 != present.end() && it2 != present.end()){
			present.erase(it1);
			present.erase(it2);
		}
	}
	cout<<setfill('0')<<present.size()<<endl;//测试点3通不过的原因是没有按照宽度为5前面填0输出！！！！ 
	for (auto it=present.begin(); it!=present.end(); it++){
		if (it!=present.begin()) cout<<' ';
		cout<<setw(5)<<*it;    
	}
}
