/*#include <bits/stdc++.h>//这个方法第三个测试点会超时，时间复杂度100*1000*1000 
using namespace std;

int main(){
	ios::sync_with_stdio(false);//经过测试，对性能起明显优化作用的是这条语句 
	cin.tie(NULL);
	int n, m;
	unordered_map<int, unordered_set<int> > mp;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int first, second;
		cin>>first>>second;
		if(first<second){
			mp[first].insert(second);
		}else{
			mp[second].insert(first);
		}
	}
	for(int i=0; i<m; i++){
		int k;
		cin>>k;
		vector<int> good(k);
		for(auto &it : good) cin>>it;
		sort(good.begin(), good.end());
		bool flag = true;
		for(int x=0; flag && x<k-1; x++)//看k个输入序列中的每个序列的每两个货物在不在冲突货物表中，时间复杂度1000*1000 
			for(int y=x+1; y<k; y++)
				if(mp[good[x]].find(good[y]) != mp[good[x]].end()){
					flag = false;
					break;
				}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}*/
#include <bits/stdc++.h>//时间复杂度100*10000
using namespace std;
bool good[100000] = {false};

int main(){
	ios::sync_with_stdio(false);//经过测试，对性能起明显优化作用的是这条语句 
	int n, m, i, first, second;
	cin>>n>>m;
	vector<pair<int, int> > list(n);
	for(i=0; i<n; i++){
		cin>>first>>second;
		list[i] = pair<int, int>(first, second);
		//list[i] = make_pair(first, second);上面一条语句的代替用法 
	}
	for(i=0; i<m; i++){
		fill(good, good+100000, false);
		int k, tmp;
		cin>>k;
		for(int x=0; x<k; x++){
			cin>>tmp;
			good[tmp] = true;
		}
		bool flag = true;
		for(auto t : list){//看冲突货物表中的每对货物在不在k个输入序列其中的一个序列中，时间复杂度10000 
			if(good[t.first] && good[t.second]){
				flag = false;
				break;
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		//printf("%s\n", flag?"Yes":"No");//可用这个语句替换上面的输出语句 
	}
	return 0;
}
