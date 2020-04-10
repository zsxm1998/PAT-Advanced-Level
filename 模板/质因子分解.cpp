#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;//素数表表长
int prime[maxn], pNum = 0;//素数表和素数个数
bool p[maxn] = {false};//p[1] == true表示i是素数
bool isPrime(int n){
	if(n < 2) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i=2; i<=sqr; i++){
		if(n % i == 0) return false;
	}
	return true;
}
void findPrime(){
	for(int i=0; i<maxn; i++){
		if(isPrime(i)){
			prime[pNum++] = i;
			p[i] = true;
		}
	}
} 

struct factor{
	int x, cnt;
}fac[10];//对一个int型的数据来说开到10就够了

int main(){
	findPrime();
	int n, num=0;
	cin>>n; 
	if(n < 2){
		cout<<"无法分解质因子！";
		return 0; 
	}
	int sqr = (int)sqrt(1.0 * n);
	for(int i=0; prime[i]<=sqr; i++){
		if(n % prime[i] == 0){
			fac[num].x = prime[i];
			fac[num].cnt = 0;
			while(n % prime[i] == 0){
				fac[num].cnt++;
				n /= prime[i];
			}
			num++;
		}
		if(n == 1) break;//及时退出循环，节省点时间 
	}
	if(n != 1){//如果n无法被根号n以内的质因子除尽 
		fac[num].x = n;//那么一定有且仅有一个大于根号n的质因子 
		fac[num++].cnt = 1;
	}
	for(int i=0; i<num; i++){
		while(fac[i].cnt--){
			cout<<fac[i].x<<' ';
		}
	}
	return 0; 
}
 
