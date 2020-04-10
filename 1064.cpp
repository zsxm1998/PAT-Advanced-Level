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
	if(root*2 <= n)//����ж�����ע�͵�Ҳ���ԣ���Ϊ����ǰ�ڵ�û�������������ʼ��if���ͷ����ˣ�����������ͱض��������� 
		putinto(root*2, first, mid-1);
	if(root*2+1 <= n)//����ж�����ע�͵��������Ϊ��ǰ�ڵ����û�������������������Ľڵ��Ŵ���n���������������ж�������δ��� 
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

