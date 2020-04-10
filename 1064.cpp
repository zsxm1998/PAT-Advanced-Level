#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> input, level;
void putinto(int root, int first, int last){
	if(first == last){
		level[root] = input[first];
		return;
	}
	int l = 1, m = last - first +1;
	while(pow(2, l) - 1 < m) l++;
	int pow2l = (int)pow(2, l);
	int lastlevelnum = m - (pow2l/2 - 1);
	int leftsubnum = min(pow2l/4, lastlevelnum) + (pow2l/2-2)/2;
	int mid = first + leftsubnum;
	level[root] = input[mid];
	if(root*2 <= n)//这个判断条件注释掉也可以，因为若当前节点没有左子树则在最开始的if处就返回了，到达了这里就必定有左子树 
		putinto(root*2, first, mid-1);
	if(root*2+1 <= n)//这个判断条件注释掉会出错，因为当前节点可能没有右子树，即右子树的节点编号大于n，故如果不加这个判断条件会段错误 
		putinto(root*2+1, mid+1, last);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	input.resize(n+1);
	level.resize(n+1);
	for(int i=1; i<=n; i++) cin>>input[i];
	sort(input.begin()+1, input.end());
	putinto(1, 1, n);
	for(int i=1; i<=n; i++){
		if(i != 1) cout<<' ';
		cout<<level[i];
	}
	return 0;
}

