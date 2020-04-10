#include <bits/stdc++.h>
using namespace std;
struct node{
	int lchild = 0, rchild = 0;
}memo[31];
vector<int> post;
void postorder(int root){
	if(memo[root].lchild) postorder(memo[root].lchild);
	if(memo[root].rchild) postorder(memo[root].rchild);
	post.push_back(root);
}
int main(){
	if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	int n, pre = 0, u;
	cin>>n;
	stack<int> st;
	bool turnR = false;
	for(int i=0; i<2*n; i++){
		string op;
		cin>>op;
		if(op == "Push"){
			cin>>u;
			if(turnR){
				memo[pre].rchild = u;
				turnR = false;
			}else memo[pre].lchild = u;
			st.push(u);
			pre = u;
		}else if(op == "Pop"){
			pre = st.top();
			st.pop();
			turnR = true;
		}
	}
	postorder(memo[0].lchild);
	for(int i=0; i<post.size(); i++){
		cout<<(i?" ":"")<<post[i];
	}
	return 0;
}

