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
	int maxnum = 0, j=0;//�������Ż��Ĺؼ�������֮�󣬺�һ��Ԫ��*pһ������ǰһ��Ԫ��*p 
	for(int i=0; i<n; i++){//��ÿ�����i��ѭ��ʱj����һ��ѭ���Ľ���Ϊֹ��ʼ�����Խ�ʱ�临�Ӷ���On2���͵�On 
		ll max = seq[i] * p;
		for(; j<n && seq[j]<=max; j++);
		int num = j - i;
		if(num > maxnum) maxnum = num;
		if(j == n) break;//��j���б��βʱ��ʱ��������Ϊ��ʱi������subseq�ĳ�����Զ�����̵� 
	}
	cout<<maxnum;
	return 0;
}

