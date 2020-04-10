#include <bits/stdc++.h>
using namespace std;
struct mooncake{
	double weight, tprice, price;
	friend bool operator<(const mooncake &a, const mooncake &b){
		return a.price > b.price;
	}
};
int main(){
	ios::sync_with_stdio(false);
	int n, d;
	cin>>n>>d;
	vector<mooncake> v(n);
	for(int i=0; i<n; i++){
		cin>>v[i].weight;
	}
	for(int i=0; i<n; i++){
		cin>>v[i].tprice;
		v[i].price = v[i].tprice / v[i].weight;
	}
	sort(v.begin(), v.end());
	double sell = 0;
	int i = 0;
	while(d && i<n){
		if(v[i].weight <= d){
			sell += v[i].tprice;
			d -= v[i].weight;
		}else{
			sell += v[i].price * d;
			d = 0;
		}
		i++;
	}
	cout<<fixed<<setprecision(2)<<sell;
	return 0;
}

