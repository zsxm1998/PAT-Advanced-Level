#include <bits/stdc++.h>
using namespace std;
double odd[3][3], choose[3], ansnum = 1;
char type[3] = {'W', 'T', 'L'}, ans[3]; 
int main(){
	ios::sync_with_stdio(false);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin>>odd[i][j];
		}
	}
	for(int i=0; i<3; i++){
		double maxodd = odd[i][0];//这里要用double而不是int 
		int maxidx = 0;
		for(int j=1; j<3; j++){
			if(odd[i][j] > maxodd){
				maxodd = odd[i][j];
				maxidx = j;
			}
		}
		choose[i] = maxodd;
		ans[i] = type[maxidx];
	}
	for(int i=0; i<3; i++){
		cout<<ans[i]<<' ';
		ansnum *= choose[i];
	}
	cout<<fixed<<setprecision(2)<<(ansnum*0.65-1)*2;
	return 0;
}

