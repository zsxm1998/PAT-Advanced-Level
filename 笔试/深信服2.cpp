#include <iostream>
#include <string>
using namespace std;

int main(){
	int k;
	cin>>k;
	string key[k];
	for(int i=0;i<k;i++){
		cin>>key[i];
	}
	bool flag = false;
	string text;
	cin>>text;
	for(int i=0;i<k;i++){
		while(text.find(key[i]) != string::npos){
			text.erase(text.find(key[i]), key[i].length());
			flag = true;
		}
	}
	if(flag && text.length()==0){
		cout<<"yes";
	}else{
		cout<<"no";
	}
	return 0; 
} 
