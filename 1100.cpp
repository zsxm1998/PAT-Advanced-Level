#include <bits/stdc++.h>
using namespace std;
string low[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string high[13] = {"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
map<string, int> mp;
void init(){
	mp["tret"] = 0,mp["jan"] = 1,mp["feb"] = 2,mp["mar"] = 3,mp["apr"] = 4,mp["may"] = 5,mp["jun"] = 6,mp["jly"] = 7,mp["aug"] = 8,mp["sep"] = 9,mp["oct"] = 10,mp["nov"] = 11,mp["dec"] = 12;
	mp["tam"] = 1*13,mp["hel"] = 2*13,mp["maa"] = 3*13,mp["huh"] = 4*13,mp["tou"] = 5*13,mp["kes"] = 6*13,mp["hei"] = 7*13,mp["elo"] = 8*13,mp["syy"] = 9*13,mp["lok"] = 10*13,mp["mer"] = 11*13,mp["jou"] = 12*13;
}
int main(){
	ios::sync_with_stdio(false);
	init();
	int n;
	cin>>n;
	cin.get();
	while(n--){
		string in;
		getline(cin, in);
		if(isdigit(in[0])){
			int num = stoi(in);
			string out;
			if(num / 13 == 0) out = low[num%13];
			else{
				if(num % 13 == 0) out = high[num/13];
				else out = high[num/13] + " " + low[num%13];
			}
			cout<<out<<endl;
		}else{
			int num = 0;
			if(in.size() == 3){
				num = mp[in];
			}else{
				num = mp[in.substr(0, 3)] + mp[in.substr(4, 3)];
			}
			cout<<num<<endl;
		}
	}
	return 0;
}

