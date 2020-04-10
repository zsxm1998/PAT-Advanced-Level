#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
	int key, value, op, time;
	node(int k, int v, int o, int t){
		key=k;
		value=v;
		op=o;
		time=t;
	}
};
vector<node> pool;

bool cmp(node a, node b){
	if(a.op != b.op){
		return a.op > b.op;
	}else{
		return a.time > b.time;
	}
}

int get(int key, int time){
	for(int i=0; i<pool.size(); i++){
		if(pool[i].key == key){
			pool[i].op += 1;
			pool[i].time = time;
			//cout<<"tttest "<<pool[i].key<<pool[i].value<<pool[i].op<<pool[i].time<<endl;
			return pool[i].value;
		}else{
			pool[i].op -= 1;
		}
	}
	return -1;
}

int main(){
	int n, l;
	cin>>n>>l;
	for(int i=0;i<l;i++){
		char type;
		cin>>type;
		if(type == 's'){
			int key, value;
			cin>>key>>value;
			if(pool.size() < n){
				pool.push_back(node(key, value, 1, i));
			}else{
				sort(pool.begin(), pool.end(), cmp);
				/*for(int j=0; j<pool.size();j++){
					cout<<"tttest "<<pool[j].key<<pool[j].value<<pool[j].op<<pool[j].time<<endl;
				}*/
				pool.pop_back();
				pool.push_back(node(key, value, 1, i));
			}
		}
		else if(type == 'g'){
			int key;
			cin>>key;
			cout<<get(key, i)<<endl;
		}
	}
	return 0;
}
