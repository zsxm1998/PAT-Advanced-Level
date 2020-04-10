#include<bits/stdc++.h>
using namespace std;
vector<int> pre, in, post;
bool uniqueFlag = true;

void getInFromPreAndPost(int prel, int prer, int postl, int postr){//直接通过先序序列和后序序列打印中序序列 
	if(prel == prer){
		in.push_back(pre[prel]);
		return;
	}
	int i=prel + 1;
	while(pre[i]!=post[postr-1]){//在先序序列中找到右子树的根节点位置 
		i++;
	}
	if(i-prel > 1){//当前树有两颗子树 
		int numl = i-prel-1;
		getInFromPreAndPost(prel+1, prel+numl, postl, postl+numl-1);
		in.push_back(pre[prel]);
		getInFromPreAndPost(i, prer, postl+numl, postr-1);
	}else{//当前树只有一颗子树，无法确定是左子树还是右子树，这里认为是左子树进行打印 
		uniqueFlag = false;
		getInFromPreAndPost(i, prer, postl, postr-1);
		in.push_back(pre[prel]);
	}
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	pre.resize(n);
	post.resize(n);
	for(int i=0; i<n; i++){
		cin>>pre[i];
	}
	for(int i=0; i<n; i++){
		cin>>post[i];
	}
	getInFromPreAndPost(0, n-1, 0, n-1);
	cout<<(uniqueFlag?"Yes":"No")<<endl;//printf("%s\n", uniqueFlag?"Yes":"No");
	cout<<in[0];
	for(int i=1; i<n; i++){
		cout<<' '<<in[i];
	}
	cout<<endl;
	return 0;
}
