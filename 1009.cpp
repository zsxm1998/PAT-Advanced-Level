#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	map<int, double> mp[3];
	for(int i=0; i<2; i++){
		int k;
		cin>>k;
		for(int j=0; j<k; j++){
			int n;
			double a;
			cin>>n>>a;
			if(a != 0) mp[i][n] = a;//ϵ��Ϊ0������������õļ����ҿ��ܻᵼ�½������ 
		}
	}
	for(auto it1=mp[0].begin(); it1!=mp[0].end(); it1++){
		for(auto it2=mp[1].begin(); it2!=mp[1].end(); it2++){
			mp[2][it1->first+it2->first] += it1->second*it2->second;
		}
	}
	int cnt = 0;
	for(auto it=mp[2].begin(); it!=mp[2].end(); it++) if(it->second != 0) cnt++;
	cout<<fixed<<setprecision(1)<<cnt;//���Ե�0��ϵ��Ϊ0����� 
	for(map<int,double>::reverse_iterator rit=mp[2].rbegin(); rit!=mp[2].rend(); rit++){
		if(rit->second == 0) continue;//���Ե�0��ϵ��Ϊ0����� 
		cout<<' '<<rit->first<<' '<<rit->second;
	}
	return 0;
}

