#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	streambuf* cinbackup = cin.rdbuf(fin.rdbuf());
	streambuf* coutbackup = cout.rdbuf(fout.rdbuf());
char st[1024];
while(cin.getline(st, 1024)){
    cout<<st<<endl;
}



}
