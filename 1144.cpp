/*#include <bits/stdc++.h>//������������Լ�д�ģ����ر�������ͨ����OJ����AC 
using namespace std;

bool visited[INT_MAX] = {false};

int main(){
	ios::sync_with_stdio(false);
	int n, tmp;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>tmp;
		if(tmp>0) visited[tmp] = true;
	}
	for(int i=1; i<INT_MAX; i++){
		if(!visited[i]){
			cout<<i;
			break;
		}
	}
	return 0;
}*/
#include <bits/stdc++.h> //����������S��˼·��map 
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	map<int, int> mp;
	int n, tmp;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>tmp;
		mp[tmp]++;
	}
	int i=0;
	while(++i){
		if(!mp[i]) break;
	}
	cout<<i;
} 
