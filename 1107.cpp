#include <bits/stdc++.h>
using namespace std;
int first[1001] = {0}, father[1001], cnt[1001] = {0};
int findfather(int x){
	int a = x;
	while(x != father[x]) x = father[x];
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void merge(int a, int b){
	int fa = findfather(a), fb = findfather(b);
	if(fa != fb) father[fa] = fb;
}
int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) father[i] = i;
	for(int i=1; i<=n; i++) {
		int k;
		char c;
		cin>>k>>c;
		while(k--){
			int h;
			cin>>h;
			if(first[h] == 0){
				first[h] = i;
			}else{
				merge(i, first[h]);
			}
		}
	}
	for(int i=1; i<=n; i++){
		cnt[findfather(i)]++;
	}
	multiset<int, greater<int>> out;
	for(int i=1; i<=n; i++){
		if(cnt[i] != 0){
			out.insert(cnt[i]);
		}
	}
	cout<<out.size();
	for(auto it=out.begin(); it!=out.end(); it++){
		cout<<(it==out.begin()?'\n':' ')<<*it;
	}
	return 0;
}

