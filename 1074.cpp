#include <bits/stdc++.h>
using namespace std;
struct node{
	int data, next;
	node(){data = next = -1;};
	node(int x, int nxt){
		data = x;
		next = nxt;
	}
}memo[100010];
int first, n, k, start = 100001;
int main(){
	if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	cin>>first>>n>>k;
	memo[start].next = first;
	for(int i=0; i<n; i++){
		int add, data, next;
		cin>>add>>data>>next;
		memo[add] = node(data, next);
	}
	bool haveEle = true;
	while(haveEle){
		int p = start, p2 = memo[start].next, cnt = 0, sbackup;
		while(cnt < k){
			p = memo[p].next;
			if(p == -1){
				haveEle = false;
				break;
			}
			cnt++;
		}
		while(haveEle && cnt--){
			int nxtp = memo[p2].next;
			if(p2 == memo[start].next){
				memo[p2].next = memo[p].next;
				sbackup = p2;
			}else{
				memo[p2].next = memo[start].next;
			}
			memo[start].next = p2;
			p2 = nxtp;
		}
		start = sbackup;
	}
	cout<<setfill('0');
	start = memo[100001].next;
	while(start != -1){
		cout<<setw(5)<<start<<' '<<memo[start].data<<' ';
		if(memo[start].next == -1) cout<<memo[start].next<<endl;
		else cout<<setw(5)<<memo[start].next<<endl;
		start = memo[start].next;
	}
	return 0;
}

