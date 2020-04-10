#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, first, cnt = 0;//有可能有节点不在链表里，故要把参加排序的节点计数后输出（测试点1） 
struct node{
	int key, next = -1;
}memo[MAXN];
int main(){
	//if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	cin>>n>>first;
	for(int i=0; i<n; i++){
		int add;
		cin>>add;
		cin>>memo[add].key>>memo[add].next;
	}
	int head = 100005, p = first;
	while(p != -1){
		int ptmp = memo[p].next, i;
		for(i=head; memo[i].next!=-1&&memo[memo[i].next].key<memo[p].key; i=memo[i].next);
		memo[p].next = memo[i].next;
		memo[i].next = p;
		cnt++;
		p = ptmp;
	}
	p = memo[head].next;
	cout<<setfill('0')<<cnt<<' ';
	if(p == -1) cout<<p<<endl;//输入有可能是n -1，即空链表，这时候输出的头结点应该也是-1（测试点4） 
	else cout<<setw(5)<<p<<endl; 
	while(p != -1){
		cout<<setw(5)<<p<<' '<<memo[p].key<<' ';
		if(memo[p].next == -1) cout<<memo[p].next<<endl;
		else cout<<setw(5)<<memo[p].next<<endl;
		p = memo[p].next;
	}
	return 0;
}

