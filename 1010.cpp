#include <bits/stdc++.h>
using namespace std;
string n[2];
int tag, radix;
long long trans(string x, long long base){
	reverse(x.begin(), x.end());
	long long result = 0, power = 1;
	for(int i=0; i<x.size(); i++){
		result += (x[i]<='9' ? x[i]-'0' : x[i]-'a'+10) * power;
		power *= base;
	}
	return result;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n[0]>>n[1]>>tag>>radix;//���ƿ��ܲ�ֹ36 
	long long a = trans(n[tag-1], radix);
	if(tag == 2) tag = 0;
	long long maxdigit = 0;
	for(int i=0; i<n[tag].size(); i++){
		int nowdigit = (n[tag][i]<='9' ? n[tag][i]-'0' : n[tag][i]-'a'+10);
		if(nowdigit > maxdigit) maxdigit = nowdigit;
	}
	long long low = maxdigit+1, mid;//low�Ǵ���������ͺϷ����� 
	long long high = max(low, a);//��high�ߵĽ���û�в��Եı�Ҫ�� 
	while(low < high){//���ַ� 
		mid = (low + high) / 2;
		long long b = trans(n[tag], mid);
		if(b<0 || b>=a) high = mid;//b<0��������� 
		else low = mid + 1;
	}
	if(a == trans(n[tag], low)) cout<<low;
	else cout<<"Impossible";
	return 0;
}

