#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100004;
struct node{
	int data=0, next=-1;
}memory[MAXN]; 
int main(){
	ios::sync_with_stdio(false);
	int start, n, k;
	cin>>start>>n>>k;
	for(int i=0; i<n; i++){
		int u, v, w;
		cin>>u>>v>>w;
		memory[u].data = v;
		memory[u].next = w;
	}
	int tail1 = 100001, tail2 = 100002, tail3 = 100003;
	for(int i=start; i!=-1; i=memory[i].next){
		if(memory[i].data<0){
			memory[tail1].next = i;
			tail1 = i;
		}else if(memory[i].data>=0 && memory[i].data<=k){
			memory[tail2].next = i;
			tail2 = i;
		}else if(memory[i].data>k){
			memory[tail3].next = i;
			tail3 = i;
		}
	}
//	start = memory[100001].next;//注释掉的这部分是错误做法，没有考虑三个链表其中几个可能为空的情况 
//	memory[tail1].next = memory[100002].next;
//	memory[tail2].next = memory[100003].next;
//	memory[tail3].next = -1;
	if(memory[100001].next != -1){
		start = memory[100001].next;
		if(memory[100002].next != -1){
			memory[tail1].next = memory[100002].next;
			if(memory[100003].next != -1){
				memory[tail2].next = memory[100003].next;
				memory[tail3].next = -1;
			}else{
				memory[tail2].next = -1;
			}
		}else if(memory[100003].next != -1){
			memory[tail1].next = memory[100003].next;
			memory[tail3].next = -1;
		}else{
			memory[tail1].next = -1;
		}
	}else if(memory[100002].next != -1){
		start = memory[100002].next;
		if(memory[100003].next != -1){
			memory[tail2].next = memory[100003].next;
			memory[tail3].next = -1;
		}else{
			memory[tail2].next = -1;
		}
	}else if(memory[100003].next != -1){
		start = memory[100003].next;
		memory[tail3].next = -1;
	}
	for(int i=start; i!=-1; i=memory[i].next){
		cout<<setfill('0')<<setw(5)<<i<<' '<<memory[i].data<<' ';
		if(memory[i].next == -1){
			cout<<memory[i].next<<endl;
		}else{
			cout<<setw(5)<<memory[i].next<<endl;
		}
	}
}
