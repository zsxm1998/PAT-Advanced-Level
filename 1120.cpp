#include <bits/stdc++.h>
using namespace std;
int friendNum(int x){
	int sum = 0;
	while(x){
		sum += x % 10;
		x /= 10;
	}
	return sum;
}
int main(){
	set<int> fri;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		fri.insert(friendNum(x));
	}
	cout<<fri.size()<<endl;
	auto it = fri.begin();
	cout<<*it++;
	while(it != fri.end()){
		cout<<' '<<*it++;
	}
} 
