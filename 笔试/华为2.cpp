#include <bits/stdc++.h>
using namespace std;
int fac[14] = {0};
map<char, bool> huase[13];
int stringtoint(string in){
	if(in[0]=='S' || in[0]=='H' || in[0]=='C' || in[0]=='D'){
		if(in[1]=='J'){
			return 9;
		}else if(in[1]=='Q'){
			return 10;
		}else if(in[1]=='K'){
			return 11;
		}else if(in[1]=='A'){
			return 12;
		}else{
			return stoi(in.substr(1)) - 2;
		}
	}else{
		return 13;
	}
}
int findMax(){
	int powerNum = 0;
	if(fac[13] == 2){
		powerNum += 5;
		fac[13] = 0;
	}
	for(int i=0; i<13; i++){
		if(fac[i] == 4){
			powerNum += 5;
			fac[i] -= 4;
		}else if(fac[i] == 3){
			powerNum += 4;
			fac[i] -= 3;
		}
	}
	bool lineFlag = false;
	for(int i=0; i<13; i++){
		int lineCnt = 0;
		for(int j=i; j<13; j++){
			if(fac[j]>0){
				lineCnt++;
				if(lineCnt == 5){
					powerNum += 3;
					for(int k=i; k<=j; k++){
						fac[k]--;
					}
					lineFlag = true;
					break;
				}
			}else{
				break;
			}
		}
		if(lineFlag){
			lineFlag = false;
			i--;
		}
	}
	for(int i=0; i<13; i++){
		if(fac[i] == 2){
			powerNum += 2;
			fac[i] -= 2;
		}
	}
	return powerNum;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		string inputS;
		cin>>inputS;
		//cout<<stringtoint(inputS)<<endl;
		fac[stringtoint(inputS)]++;
	}
	cout<<findMax();
	return 0;
}

/*int stringtoint(string in){
	transform(in.begin(), in.end(), in.begin(), ::toupper);
	if(in[0]=='S' || in[0]=='H' || in[0]=='C' || in[0]=='D'){
		if(in[1]=='J'){
			if(huase[9][in[0]] == false){
				huase[9][in[0]] = true;
				return 9;
			}
		}else if(in[1]=='Q'){
			if(huase[10][in[0]] == false){
				huase[10][in[0]] = true;
				return 10;
			}
		}else if(in[1]=='K'){
			if(huase[11][in[0]] == false){
				huase[11][in[0]] = true;
				return 11;
			}
		}else if(in[1]=='A'){
			if(huase[12][in[0]] == false){
				huase[12][in[0]] = true;
				return 12;
			}
		}else{
			if(huase[stoi(in.substr(1)) - 2][in[0]] == false){
				huase[stoi(in.substr(1)) - 2][in[0]] = true;
				return stoi(in.substr(1)) - 2;
			}
		}
	}else if((in[0]=='J') && (in[1]=='1' || in[1]=='2')){
		return 13;
	}
	return 14;
}*/
