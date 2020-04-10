#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct factor{
	int p, k;
}fac[30];
bool isPrime(int x){
	if(x < 2) return false;
	int sqr = sqrt(x);
	for(int i=2; i<=sqr; i++){
		if(x % i == 0) return false;
	}
	return true;
}
int prime[1800], pcnt = 0, fcnt = 0;
int main(){
	ios::sync_with_stdio(false);
	for(int i=2; i<15000; i++){
		if(isPrime(i)) prime[pcnt++] = i;
	}
	LL n, sqr, N;
	cin>>n;
	sqr = sqrt(n), N = n;
	for(int i=0; prime[i]<=sqr; i++){
		if(n % prime[i] == 0){
			fac[fcnt].p = prime[i];
			fac[fcnt].k = 1;
			n /= prime[i];
			while(n % prime[i] == 0){
				fac[fcnt].k++;
				n /= prime[i];
			}
			fcnt++;
		}
	}
	if(n != 1){
		fac[fcnt].p = n;
		fac[fcnt++].k = 1;
	}
	cout<<N;
	if(N == 1) cout<<"=1";//针对测试点3的特判 
	for(int i=0; i<fcnt; i++){
		cout<<(i==0?'=':'*')<<fac[i].p;
		if(fac[i].k != 1) cout<<'^'<<fac[i].k;
	}
	return 0;
}

