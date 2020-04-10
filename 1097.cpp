#include <bits/stdc++.h>
using namespace std;
int start, n, rehead = 100001, dehead = 100002, retail = 100001, detail = 100002;
struct node{
	int data, next = -1;
}memory[100010];
bool hashTable[100010] = {false};
int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin>>start>>n;
	memory[rehead].next = start;
	for(int i=0; i<n; i++){
		int add, data, next;
		cin>>add>>data>>next;
		memory[add].data = data;
		memory[add].next = next;
	}
	for(int p=start; p!=-1; p=memory[p].next){
		if(hashTable[abs(memory[p].data)]){
			memory[detail].next = p;
			detail = p;
		}else{
			hashTable[abs(memory[p].data)] = true;
			memory[retail].next = p;
			retail = p;
		}
	}
	memory[retail].next = memory[detail].next = -1;
	cout<<setfill('0');
	for(int i=memory[rehead].next; i!=-1; i=memory[i].next){
		if(memory[i].next==-1) cout<<setw(5)<<i<<' '<<memory[i].data<<' '<<memory[i].next<<endl;
		else cout<<setw(5)<<i<<' '<<memory[i].data<<' '<<setw(5)<<memory[i].next<<endl;
	}
	for(int i=memory[dehead].next; i!=-1; i=memory[i].next){
		if(memory[i].next==-1) cout<<setw(5)<<i<<' '<<memory[i].data<<' '<<memory[i].next<<endl;
		else cout<<setw(5)<<i<<' '<<memory[i].data<<' '<<setw(5)<<memory[i].next<<endl;
	}
	return 0;
}

