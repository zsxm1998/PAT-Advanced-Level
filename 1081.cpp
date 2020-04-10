#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
	return !b ? a : gcd(b, a%b);
}
int main(){
	int n;
	scanf("%d", &n);
	ll a, b, c, d, e, f, g;
	scanf("%lld/%lld", &a, &b);
	while(--n){
		scanf("%lld/%lld", &c, &d);
		e = a * d + c * b;
		f = b * d;
		g = gcd(abs(e), abs(f));
		a = e / g;
		b = f / g;
	}
	if(b == 1) printf("%lld", a);
	else{
		if(abs(a) > b) printf("%lld %lld/%lld", a/b, a%b, b);
		else printf("%lld/%lld", a, b);
	}
	return 0;
}

