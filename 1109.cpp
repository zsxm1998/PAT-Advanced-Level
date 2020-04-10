#include <bits/stdc++.h>
using namespace std;
struct person{
	string name;
	int height;
	person(string s, int x){
		name = s;
		height = x;
	}
	friend bool operator<(const person &a, const person &b){//ÕâÀï±ØÐëÐ´const 
		return a.height != b.height ? a.height < b.height : a.name > b.name;
	}
};
int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n, k;
	cin>>n>>k; 
	int quotient = n/k, remainder = n%k;
	priority_queue<person> inq;
	vector<list<person>> out(k);
	for(int i=0; i<n; i++){
		string name;
		int height;
		cin>>name>>height;
		inq.push(person(name, height));
	}
	for(int i=0; i<k; i++){
		int num;
		if(i == 0) num = quotient + remainder;
		else num = quotient;
		for(int j=0; j<num; j++){
			person temp = inq.top();
			inq.pop();
			if(j % 2 == 1){
				out[i].push_front(temp);
			}else{
				out[i].push_back(temp);
			}
		}
	}
	for(auto &ls : out){
		for(auto it=ls.begin(); it!=ls.end(); it++){
			if(it!=ls.begin()) cout<<' ';
			cout<<it->name;
		}
		cout<<endl;
	}
	return 0;
}

