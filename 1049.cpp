#include <bits/stdc++.h>
using namespace std;
int main(){
	long long sum = 0, n, cnt = -1, remain[20], base = 1;
	cin>>n;
	while(n != 0){
		sum += n / 10 * base;
		remain[++cnt] = n % 10;
		if(remain[cnt] == 1){
			long long resum = 0, rebase = 1;
			for(int i=0; i<cnt; i++){
				resum += remain[i] * rebase;
				rebase *= 10;
			}
			sum += resum +1;
		}else if(remain[cnt] > 1){
			sum += base;
		}
		n /= 10;
		base *= 10;
	}
	cout<<sum;
}

