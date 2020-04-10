#include <bits/stdc++.h>
using namespace std;

int main(){
    string in;
    int n = 2;
    while(n--){
        getline(cin, in);
        while(in.size()){
            while((int)in.size()-8 < 0){
                //in += string("0");
                in += "0";
            }
            cout<<in.substr(0, 8)<<endl;
            in = in.substr(8);
        }
    }
}
