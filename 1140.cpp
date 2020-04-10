/*#include<bits/stdc++.h>  //此代码最后一个测试点会超时 
using namespace std;

string las(string in){
	string out = "";
	char pre[1];
	pre[0] = in[0];
	int count = 0;
	for(int i=0; i<in.length(); i++){
		if(in[i] == pre[0]){
			count++;
		}
		else{
			out = out + string(pre) + to_string(count);
			count = 0;
			pre[0] = in[i];
			i--;
		}
	}
	out = out + string(pre) + to_string(count);
	return out;
}

int main(){//char[]不可以用=赋值而string可以 
	int n;
	string input;
	cin>>input>>n;
	while(--n){
		input = las(input);
	}
	cout<<input;
	return 0;
}*/

#include<bits/stdc++.h>  //使用柳婼的思路 
using namespace std;
int main(){
	int n;
	string in;
	cin>>in>>n;
	for(int i=1; i<n; i++){
		string tmp = "";
		int j, k;
		for(j=0; j<in.length(); j=k){
			for(k = j; k<in.size() && in[k]==in[j]; k++);
			tmp += in[j] + to_string(k-j);
		}
		in = tmp;
	}
	cout<<in;
	return 0;
} 
