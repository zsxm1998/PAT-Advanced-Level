#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	map<int, double> mp[2];
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
	for(auto it=mp[1].begin(); it!=mp[1].end(); it++){
		mp[0][it->first] += it->second;
	}
	int cnt = 0;
	for(auto it=mp[0].begin(); it!=mp[0].end(); it++) if(it->second != 0) cnt++;
	cout<<fixed<<setprecision(1)<<cnt;//ϵ��Ϊ0����� 
	for(map<int,double>::reverse_iterator rit=mp[0].rbegin(); rit!=mp[0].rend(); rit++){
		if(rit->second == 0) continue;//ϵ��Ϊ0����� 
		cout<<' '<<rit->first<<' '<<rit->second;
	}
	return 0;
}

