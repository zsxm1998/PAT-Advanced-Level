#include <bits/stdc++.h>
using namespace std;
int main(){
	//if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	map<string, set<int>> mp[6];
	string instr;
	int n, m;
	cin>>n;
	while(n--){
		int id;
		cin>>id;
		cin.get();//这里一定要把第一行末的换行符吸收掉 
		for(int i=1; i<6; i++){
			getline(cin, instr);
			if(i == 3){
				instr += ' ';
				int pre = 0;
				for(int j=0; j<instr.size(); j++){
					if(instr[j] == ' '){
						mp[i][instr.substr(pre, j-pre)].insert(id);
						pre = j+1;
					}
				}
			}else{
				mp[i][instr].insert(id);
			}
		}
	}
	cin>>m;
	cin.get();//这里一定要把行末的换行符吸收掉 
	while(m--){
		getline(cin, instr);
		int kind = instr[0]-'0';
		string keyw = instr.substr(3);
		cout<<setfill('0')<<instr<<endl;
		if(mp[kind][keyw].size() == 0) cout<<"Not Found\n";
		else{
			for(auto t : mp[kind][keyw]) cout<<setw(7)<<t<<endl;
		}
	}
	return 0;
}

