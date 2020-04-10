/*
�����Ҫע��ĵ㣺
�ٸ�A��B��ͬ�����ѵ�ʱ��A�����Ѳ�����B�� B�����Ѳ�����A
�����ʱ��Ҫ�ÿ��Ϊ4�����ǰ�油0����ʹ��printf������ios��stdio��ͬ������������ 
����������+0000��-0000���޷�������������һ���ڲ���������û�г��֣��ʴ���û�п�����һ�㣩 
*/
#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> mp;
int n, m, k; 

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		mp[a].insert(b);
		mp[b].insert(a);
	}
	cin>>k;
	for(int i=0; i<k; i++){
		int a, b;
		cin>>a>>b;
		vector<pair<int, int>> result;
		for(set<int>::iterator ita = mp[a].begin(); ita != mp[a].end();ita++){
			if(*ita * a < 0 || *ita == b) continue;
			for(set<int>::iterator itb = mp[b].begin(); itb != mp[b].end();itb++){
				if(*itb * b < 0 || *itb == a) continue;
				if(mp[*ita].find(*itb) != mp[*ita].end()){
					result.push_back(make_pair(abs(*ita), abs(*itb)));
				}
			}
		}
		sort(result.begin(), result.end());
		cout<<result.size()<<endl;
		for(auto rs : result){
			cout<<setfill('0')<<setw(4)<<rs.first<<' '<<setw(4)<<rs.second<<endl;
			//printf("%04d %04d\n", rs.first, rs.second);
		}
	}
}

