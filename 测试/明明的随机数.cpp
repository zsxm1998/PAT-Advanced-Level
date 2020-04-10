#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    set<int> s;
    while(!cin.eof()){
    //while(cin>>n){
        s.clear();
        cin>>n; 
        for(int i=0; i<n; i++){
            int tmp;
            cin>>tmp;
            s.insert(tmp);
        }
        for(auto i : s){
            cout<<i<<endl;
        }
        /*int a[1100] = {0};
        cin>>n;
        for(int i=0; i<n; i++){
            int tmp;
            cin>>tmp;
            a[tmp] = 1;
        }
        for(int i=0; i<1100; i++){
        	if(a[i] == 1){
        		cout<<i<<endl;
			}
		}*/
    }
}
