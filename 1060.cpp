#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int prec;
	string a, b;
	cin>>prec>>a>>b;
	int expA, expB;
	bool flag = true;
	int firstA = a.size(), pointA = a.size(), firstB = b.size(), pointB = b.size();
	for(int i=0; i<a.size(); i++){
		if(flag && a[i]>='1' &&a[i]<='9'){
			firstA = i;
			flag = false;
		}else if(a[i] == '.') pointA = i;
	}
	if(firstA == a.size()) expA = 0;
	else expA = pointA-firstA > 0 ? pointA-firstA : pointA-firstA+1;
	flag = true;
	for(int i=0; i<b.size(); i++){
		if(flag && b[i]>='1' &&b[i]<='9'){
			firstB = i;
			flag = false;
		}else if(b[i] == '.') pointB = i;
	}
	if(firstB == b.size()) expB = 0;
	else expB = pointB-firstB > 0 ? pointB-firstB : pointB-firstB+1;
	string baseA = "", baseB = "";
	for(int i=firstA; i<a.size()&&baseA.size()<prec; i++){
		if(a[i] == '.') continue;
		baseA += a[i];
	}
	while(baseA.size()<prec) baseA += '0';
	for(int i=firstB; i<b.size()&&baseB.size()<prec; i++){
		if(b[i] == '.') continue;
		baseB += b[i];
	}
	while(baseB.size()<prec) baseB += '0';
	if(baseA==baseB && expA==expB){
		cout<<"YES 0."<<baseA<<"*10^"<<expA;
	}else{
		cout<<"NO 0."<<baseA<<"*10^"<<expA<<" 0."<<baseB<<"*10^"<<expB;
	}
}
/*数字处理法，最后两个测试点没通过 
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;
int main(){
	ios::sync_with_stdio(false);
	int prec;
	LD a, b;
	cin>>prec>>a>>b;
	stringstream ss;
	ss<<scientific<<setprecision(prec)<<a<<' '<<b;
	string strA, strB;
	ss>>strA>>strB;
	LD baseA = floor(stold(strA.substr(0,prec+2))*pow((LD)10, (LD)(prec-1))) / pow((LD)10, (LD)prec);
	LD baseB = floor(stold(strB.substr(0,prec+2))*pow((LD)10, (LD)(prec-1))) / pow((LD)10, (LD)prec);
	int expA = stoi(strA.substr(prec+3)) + 1;
	int expB = stoi(strB.substr(prec+3)) + 1;
	if(baseA==baseB && expA==expB){
		cout<<"YES "<<fixed<<setprecision(prec)<<baseA<<"*10^"<<expA;
	}else{
		cout<<"NO "<<fixed<<setprecision(prec)<<baseA<<"*10^"<<expA<<' '<<baseB<<"*10^"<<expB;
	}
	return 0;
}
*/
