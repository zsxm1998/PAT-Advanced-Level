#include <bits/stdc++.h>
using namespace std;
typedef long long ll;//单纯用int会导致后两个测试点错误，故数据类型要改用long long 
ll gcd(ll a, ll b){//求最大公约数 
	return b==0?a:gcd(b, a%b);
}
struct fraction{//分数 
	ll up, down;
	bool illegal = false;
	fraction(){}
	fraction(ll u, ll d){
		up = u;
		down = d;
	}
};
fraction reduce(fraction &result){
	if(result.down == 0){
		result.illegal = true;
		return result;
	}else if(result.down < 0){
		result.up = -result.up;
		result.down = -result.down;
	}
	if(result.up == 0){
		result.down = 1;
	}else{
		int d = gcd(abs(result.up), result.down);
		result.up /= d;
		result.down /= d;
	}
	return result;
}
fraction add(const fraction &a, const fraction &b){
	fraction result;
	result.down = a.down * b.down;
	result.up = a.up * b.down + b.up * a.down;
	return reduce(result);
} 
fraction subtract(const fraction &a, const fraction &b){
	fraction result;
	result.down = a.down * b.down;
	result.up = a.up * b.down - b.up * a.down;
	return reduce(result);
} 
fraction multi(const fraction &a, const fraction &b){
	fraction result;
	result.down = a.down * b.down;
	result.up = a.up *  b.up;
	return reduce(result);
} 
fraction divide(const fraction &a, const fraction &b){
	fraction result;
	result.down = a.down * b.up;
	result.up = a.up * b.down;
	return reduce(result);
}
void printFraction(const fraction &result){
	if(result.illegal){
		cout<<"Inf";
		return;
	}
	if(result.up < 0) cout<<'(';
	if(result.down == 1) cout<<result.up;
	else if(abs(result.up) > result.down){
		cout<<result.up/result.down<<' '<<abs(result.up%result.down)<<'/'<<result.down;
	}else{
		cout<<result.up<<'/'<<result.down;
	}
	if(result.up < 0) cout<<')';
}
int main(){
	char tmp;
	ll aup, adown, bup, bdown;
	cin>>aup>>tmp>>adown>>bup>>tmp>>bdown;
	fraction a(aup, adown), b(bup, bdown);
	reduce(a);
	reduce(b);
	printFraction(a);
	cout<<" + ";
	printFraction(b);
	cout<<" = ";
	printFraction(add(a, b));
	cout<<endl;
	printFraction(a);
	cout<<" - ";
	printFraction(b);
	cout<<" = ";
	printFraction(subtract(a, b));
	cout<<endl;
	printFraction(a);
	cout<<" * ";
	printFraction(b);
	cout<<" = ";
	printFraction(multi(a, b));
	cout<<endl;
	printFraction(a);
	cout<<" / ";
	printFraction(b);
	cout<<" = ";
	printFraction(divide(a, b));
	return 0;
}

