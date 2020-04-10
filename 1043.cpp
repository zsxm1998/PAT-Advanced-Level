#include <bits/stdc++.h>
using namespace std;
int n, pre[1001];
vector<int> output;
void build(int left, int right){
	if(left >= right){
		if(left == right) output.push_back(pre[left]);
		return;
	} 
	int mid;
	for(mid=left+1; mid<=right; mid++){
		if(pre[mid] >= pre[left]) break;
	}
	build(left+1, mid-1);
	build(mid, right);
	output.push_back(pre[left]);
}
void buildMirror(int left, int right){
	if(left >= right){
		if(left == right) output.push_back(pre[left]);
		return;
	} 
	int mid;
	for(mid=left+1; mid<=right; mid++){
		if(pre[mid] < pre[left]) break;
	}
	buildMirror(left+1, mid-1);
	buildMirror(mid, right);
	output.push_back(pre[left]);
}
bool judge(int left, int right){
	if(left >= right) return true;
	bool isRight = false;
	int mid = left+1;
	for(int i=left+1; i<=right; i++){
		if(!isRight && pre[i]>=pre[left]){
			isRight = true;
			mid = i;
		}else if(isRight && pre[i]<pre[left]) return false;
	}
	if(!isRight) mid = right+1;
	return judge(left+1, mid-1) && judge(mid, right);
}
bool judgeMirror(int left, int right){
	if(left >= right) return true;
	bool isRight = false;
	int mid = left+1;
	for(int i=left+1; i<=right; i++){
		if(!isRight && pre[i]<pre[left]){
			isRight = true;
			mid = i;
		}else if(isRight && pre[i]>=pre[left]) return false;
	}
	if(!isRight) mid = right+1;
	return judgeMirror(left+1, mid-1) && judgeMirror(mid, right);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	if(n == 1){
		cin>>pre[0];
		cout<<"YES\n"<<pre[0];
		return 0;
	}
	for(int i=0; i<n; i++) cin>>pre[i];
	if(pre[0] > pre[1]){
		if(judge(0, n-1)){
			cout<<"YES";
			build(0, n-1);
		}else{
			cout<<"NO";
			return 0;
		}	
	}else{
		if(judgeMirror(0, n-1)){
			cout<<"YES";
			buildMirror(0, n-1);
		}else{
			cout<<"NO";
			return 0;
		}
	}
	for(int i=0; i<output.size(); i++){
		cout<<(i==0?'\n':' ')<<output[i];
	}
	return 0;
}

