#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		int n;
		cin>>n;
		int pst[n];
		bool put[1001]={false};
		bool flag = true;
		for(auto &in:pst){
			cin>>in;
		}
		for(int j=0;j<n;j++){
			if(put[pst[j]]){
				flag = false;
			}else{
				put[pst[j]]=true;
			}
			for(int t=0;t<j;t++){
				if(abs(t-j) == abs(pst[t]-pst[j])){
					flag=false;
					break;
				}
			}
			if(!flag){	
				break;
			}
		}
		if(flag){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}
