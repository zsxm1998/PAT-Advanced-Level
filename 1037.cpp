#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int nc, np;
	cin>>nc;
	vector<int> coupon(nc);
	for(int i=0; i<nc; i++) cin>>coupon[i];
	cin>>np;
	vector<int> product(np);
	for(int i=0; i<np; i++) cin>>product[i];
	sort(coupon.begin(), coupon.end(), greater<int>());
	sort(product.begin(), product.end(), greater<int>());
	int i = 0, ans = 0;
	while(i<coupon.size() && i<product.size() && coupon[i]>0 && product[i]>0){
		ans += coupon[i] * product[i];
		i++;
	}
	sort(coupon.begin(), coupon.end());
	sort(product.begin(), product.end());
	i = 0;
	while(i<coupon.size() && i<product.size() && coupon[i]<0 && product[i]<0){
		ans += coupon[i] * product[i];
		i++;
	}
	cout<<ans;
	return 0;
}

