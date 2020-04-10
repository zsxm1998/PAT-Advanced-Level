#include <bits/stdc++.h>
using namespace std;

int main(){
	list<int> ls;
	for(int i=0; i<10; i++) ls.push_back(i);
	auto it = ls.begin();
	advance(it, 2);
	auto it2 = ls.end();
	advance(it2, -2);
	cout<<*it<<endl<<*it2<<endl;
	for(auto i:ls) cout<<i;
	cout<<endl;
	auto it3 = ls.erase(it, it2);
	cout<<*it<<endl<<*it2<<endl<<*it3<<endl;
	for(auto i:ls) cout<<i;
	cout<<endl;
	cout<<*it<<endl;
	it--;
	cout<<*it<<endl;
	cout<<*it2<<endl;
	it2--;
	it2--;
	cout<<*it2<<endl;
	cout<<*it3<<endl;
	it3--;
	cout<<*it3<<endl;
	/*if(it != ls.end()) cout<<*it;
	else cout<<"end";*/
	return 0;
}

