#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	string Mname, Mid, Fname, Fid, tname, tid;
	int Mscore = 101, Fscore = -1, tscore, n;
	char gender;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>tname>>gender>>tid>>tscore;
		if(gender == 'M'){
			if(tscore < Mscore){
				Mscore = tscore;
				Mname = tname;
				Mid = tid;
			}
		}else{
			if(tscore > Fscore){
				Fscore = tscore;
				Fname = tname;
				Fid = tid;
			}
		}
	}
	if(Fname == "") cout<<"Absent\n";
	else cout<<Fname<<' '<<Fid<<endl;
	if(Mname == "") cout<<"Absent\n";
	else cout<<Mname<<' '<<Mid<<endl;
	if(Mname == "" || Fname == "") cout<<"NA";
	else cout<<Fscore-Mscore;
	return 0;
}

