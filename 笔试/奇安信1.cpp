#include <iostream>
#include <queue> 
#include <vector>
#include <map>
#include <cstdio>
using namespace std;
int main(){
	unsigned int tmp;
	vector<unsigned int> pid;
	map<unsigned int, unsigned int>father;
	cin>>tmp;
	pid.push_back(tmp);
	while(cin.get()!='\n'){
		cin>>tmp;
		pid.push_back(tmp);
	}
	int i=0;
	cin>>tmp;
	father[pid[i++]]=tmp;
	while(cin.get()!='\n'){
		cin>>tmp;
		father[pid[i++]]=tmp;
	}
	unsigned int endpid, count=0;
	cin>>endpid;
	queue<unsigned int>q;
	q.push(endpid);
	count++;
	while(!q.empty()){
		unsigned int son=q.front();
		q.pop();
		for(map<unsigned int, unsigned int>::iterator it=father.begin();it != father.end(); it++){
			//cout<<it->first<<"------>"<<it->second<<endl;
			if(it->second==son){
				count++;
				q.push(it->first);
			}
		}
	}
	cout<<count;
}
