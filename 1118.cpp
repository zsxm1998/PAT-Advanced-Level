#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int father[maxn];
int findFather(int x){ //�������һ��Ҫ�����·��ѹ���İ汾��������ļ򵥰汾�ᵼ�²��Ե�4��ʱ 
	int a = x;
	while(father[x] != x){
		x = father[x];
	}
	int z;
	while(father[a] != a){
		z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
/*int findFather(int x){//�������ڼ��ϵĸ��ڵ� 
	while(x != father[x]){
		x = father[x];
	}
	return x;
} */
void merge(int a, int b){
	int faA = findFather(a), faB = findFather(b);
	if(faA != faB) father[faA] = faB;
}
int main(){
	ios::sync_with_stdio(false);
	for(int i=0; i<maxn; i++){
		father[i] = i;
	}
	int n, max = 0;
	cin>>n;
	for(int i=0; i<n; i++){
		int k, s;
		cin>>k;
		for(int j=0; j<k; j++){
			int b;
			cin>>b;
			if(j == 0) s = b;
			else merge(s, b);
			if(b > max) max = b;
		}
	}
	int treeNum = 0;
	for(int i=1; i<=max; i++){
		if(father[i] == i) treeNum++;
	}
	cout<<treeNum<<' '<<max<<endl;
	int q;
	cin>>q;
	for(int i=0; i<q; i++){
		int a, b;
		cin>>a>>b;
		int faA = findFather(a), faB = findFather(b);
		if(faA == faB) cout<<"Yes\n";
		else cout<<"No\n";
	}
}
