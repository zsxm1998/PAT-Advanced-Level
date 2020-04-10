#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, p;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>p;
	vector<ll> seq(n);
	for(int i=0; i<n; i++){
		cin>>seq[i];
	}
	sort(seq.begin(), seq.end());
	int maxnum = 0, j=0;//这里是优化的关键，排序之后，后一个元素*p一定大于前一个元素*p 
	for(int i=0; i<n; i++){//故每次针对i的循环时j从上一次循环的结束为止开始，可以将时间复杂度由On2降低到On 
		ll max = seq[i] * p;
		for(; j<n && seq[j]<=max; j++);
		int num = j - i;
		if(num > maxnum) maxnum = num;
		if(j == n) break;//在j到列表结尾时及时跳出，因为此时i再增加subseq的长度永远是缩短的 
	}
	cout<<maxnum;
	return 0;
}

