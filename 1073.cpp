#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int main(){
	ios::sync_with_stdio(false);
	string in;
	cin>>in;
	int diviPos = in.find("E");
	int exp = stoi(in.substr(diviPos+1)), prec = diviPos - 2;
	if(in[0] == '-') cout<<'-';
	string outnum = in.substr(1,diviPos-1);
	outnum.erase(1, 1);//»òÕßÊÇoutnum.erase(outnum.begin()+1) 
	exp -= prec - 1;
	if(exp >= 0){
		cout<<outnum;
		while(exp--){
			cout<<'0';
		}
	}else if(abs(exp) < outnum.size()){
		outnum.insert(outnum.size()-abs(exp), 1, '.');
		cout<<outnum;
	}else{
		cout<<"0.";
		int remain = abs(exp) - outnum.size();
		while(remain--){
			cout<<'0';
		}
		cout<<outnum;
	}
	return 0;
}

