#include <bits/stdc++.h>
using namespace std;
int fnum[10000];
bool vis[10000] = {false};
struct family{
	set<int> member;
	int estate, area, id;
	double avges, avgar;
	friend bool operator<(family a, family b){
		return a.avgar != b.avgar ? a.avgar > b.avgar : a.id < b.id;
	}
};
struct property{
	int estate = 0, area = 0;
}person[10000];
map<int, family> mp;
int findFamily(int x){
	int a = x;
	while(x != fnum[x]) x = fnum[x];
	while(a != fnum[a]){
		int z = a;
		a = fnum[a];
		fnum[z] = x;
	}
	return x;
}
void merge(int a, int b){
	int fa = findFamily(a), fb = findFamily(b);
	if(fa != fb) fnum[fa] = fb;
}
int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	for(int i=0; i<10000; i++) fnum[i] = i;
	int n;
	cin>>n;
	while(n--){
		int id, cnum, estate, area;
		cin>>id;
		vis[id] = true;
		for(int i=0; i<2; i++){
			int parent;
			cin>>parent;
			if(parent != -1){
				merge(id, parent);
				vis[parent] = true;
			}
		}
		cin>>cnum;
		while(cnum--){
			int child;
			cin>>child;
			merge(id, child);
			vis[child] = true;
		}
		cin>>estate>>area;
		person[id].estate = estate;
		person[id].area = area;
	}
	for(int i=0; i<10000; i++){
		if(vis[i]){
			int fanum = findFamily(i);
			mp[fanum].member.insert(i);
			mp[fanum].estate += person[i].estate;
			mp[fanum].area += person[i].area;
		}
	}
	vector<family> outline;
	for(auto &it : mp){
		outline.push_back(it.second);
	}
	for(auto &it : outline){
		it.id = *(it.member.begin());
		it.avges = (double)it.estate / it.member.size();
		it.avgar = (double)it.area / it.member.size();
	}
	sort(outline.begin(), outline.end());
	cout<<outline.size()<<endl<<fixed<<setprecision(3)<<setfill('0');
	for(auto &it : outline){
		cout<<setw(4)<<it.id<<' '<<it.member.size()<<' '<<it.avges<<' '<<it.avgar<<endl;
	}
	return 0;
}

