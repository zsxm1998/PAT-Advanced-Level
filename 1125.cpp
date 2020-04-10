#include <bits/stdc++.h>
using namespace std;

int main(){
	priority_queue<double, vector<double>, greater<double>> heap;
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		double temp;
		cin>>temp;
		heap.push(temp);
	}
	while(heap.size()>1){
		double a, b;
		a = heap.top();
		heap.pop();
		b = heap.top();
		heap.pop();
		heap.push((a+b)/2);
	}
	cout<<(int)heap.top();
} 
