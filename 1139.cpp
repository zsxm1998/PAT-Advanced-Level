/*
这个题要注意的点：
①给A和B找同性朋友的时候，A的朋友不能是B， B的朋友不能是A
②输出时候要用宽度为4输出，前面补0，若使用printf输出则打开ios与stdio的同步，否则会出错 
③若输入是+0000或-0000则无法区分正负（这一点在测试用例中没有出现，故代码没有考虑这一点） 
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

