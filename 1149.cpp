/*#include <bits/stdc++.h>//����������������Ե�ᳬʱ��ʱ�临�Ӷ�100*1000*1000 
using namespace std;

int main(){
	ios::sync_with_stdio(false);//�������ԣ��������������Ż����õ���������� 
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
		for(int x=0; flag && x<k-1; x++)//��k�����������е�ÿ�����е�ÿ���������ڲ��ڳ�ͻ������У�ʱ�临�Ӷ�1000*1000 
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
#include <bits/stdc++.h>//ʱ�临�Ӷ�100*10000
using namespace std;
bool good[100000] = {false};

int main(){
	ios::sync_with_stdio(false);//�������ԣ��������������Ż����õ���������� 
	int n, m, i, first, second;
	cin>>n>>m;
	vector<pair<int, int> > list(n);
	for(i=0; i<n; i++){
		cin>>first>>second;
		list[i] = pair<int, int>(first, second);
		//list[i] = make_pair(first, second);����һ�����Ĵ����÷� 
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
		for(auto t : list){//����ͻ������е�ÿ�Ի����ڲ���k�������������е�һ�������У�ʱ�临�Ӷ�10000 
			if(good[t.first] && good[t.second]){
				flag = false;
				break;
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		//printf("%s\n", flag?"Yes":"No");//�����������滻����������� 
	}
	return 0;
}
