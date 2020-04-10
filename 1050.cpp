#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
char str1[MAXN];
//bool deleted[MAXN] = {false};
map<char, bool> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.getline(str1, MAXN);
	char c;
	while((c=cin.get()) != '\n') mp[c] = true;
	for(int i=0; str1[i] != '\0'; i++){
		if(mp[str1[i]] == false) cout<<str1[i];
	}
	return 0;
}

