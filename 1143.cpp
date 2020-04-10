/*#include <cstdio>
#include <vector>

using namespace std;

struct Node{
	int data;
	Node* lchild;
	Node* rchild;
};

vector<int> pre;

Node* createTree(int left, int right){
	if(left>right){
		return NULL;
	}
	int mid;
	for(mid=left+1;mid<=right && pre[mid]<pre[left]; mid++){}
	Node* root = new Node;
	root->data = pre[left];
	root->lchild = createTree(left+1, mid-1);
	root->rchild = createTree(mid, right);
	return root;
}

bool postorder(Node* root, vector<int> &path, int digit){
	if(root == NULL){
		return false;
	}
	path.push_back(root->data);
	if(postorder(root->lchild, path, digit)){
		return true;
	}
	if(postorder(root->rchild, path, digit)){
		return true;
	}
	if(root->data == digit){
		return true;
	}
	else{
		path.pop_back();
		return false;
	}
}

void printAnswer(int U, int V, vector<int> &pathU, vector<int> &pathV){
	int i=0, flag=0;
	while(!flag){
		if(pathU[i] != pathV[i]){
			flag = 1;
		}
		else if(i == pathU.size()-1){
			flag = 2;
		}
		else if(i == pathV.size()-1){
			flag = 3;
		}
		else{
			i++;
		}
	} 
	switch(flag){
		case 1:
			printf("LCA of %d and %d is %d.\n", U, V, pathU[i-1]);
			break;
		case 2:
			printf("%d is an ancestor of %d.\n", U, V);
			break;
		case 3:
			printf("%d is an ancestor of %d.\n", V, U);
			break;
	}
}

int main(){
	int M, N;
	scanf("%d%d", &M, &N);
	pre.resize(N);
	for(int i=0; i<N; i++){
		scanf("%d", &pre[i]);
	}
	Node* BST = createTree(0, N-1);
	for(int i=0; i<M; i++){
		int U, V, flag = 0;
		scanf("%d%d", &U, &V);
		vector<int> pathU;
		if(postorder(BST, pathU, U)){
			flag += 1;
		}
		vector<int> pathV;
		if(postorder(BST, pathV, V)){
			flag += 2;
		}
		switch(flag){
			case 0:
				printf("ERROR: %d and %d are not found.\n", U, V);
				break;
			case 1:
				printf("ERROR: %d is not found.\n", V);
				break;
			case 2:
				printf("ERROR: %d is not found.\n", U);
				break;
			case 3:
				printAnswer(U, V, pathU, pathV);
				break;
		}
	}
	return 0;
}*/
#include <cstdio>//此代码还是会导致一个测试点超时，可能是测试数据对层数过深导致的超时？ 
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> pre;
unordered_map<int, int> pos;

void lca(int left, int right, int u, int v){
	if(left>right){
		return;
	}
	int mid, posu = pos[u], posv = pos[v];
	for(mid=left+1; mid<=right && pre[mid]<pre[left]; mid++){}
	if(posu==left || posv == left){//这个判断一定要放在下一判断的前面否则会出错 
		printf("%d is an ancestor of %d.\n", posu==left?u:v, posu==left?v:u);
	}else if(posu>=mid&&posv<mid || posv>=mid&&posu<mid){//posu或posv<mid时有可能等于left，所以本条判断要放在第一条后面 
		printf("LCA of %d and %d is %d.\n", u, v, pre[left]);
	}else if(posu<mid && posv<mid){
		lca(left+1, mid-1, u, v);
	}else if(posu>=mid && posv>=mid){
		lca(mid, right, u, v);
	}
}

int main(){
	int M, N;
	scanf("%d%d", &M, &N);
	pre.resize(N+1);
	for(int i=1; i<=N; i++){
		scanf("%d", &pre[i]);
		pos[pre[i]] = i;
	}
	for(int i=0; i<M; i++){
		int U, V, flag = 0;
		scanf("%d%d", &U, &V);
		if(pos[U] == 0 && pos[V] == 0){
			printf("ERROR: %d and %d are not found.\n", U, V);
		}
		else if (pos[U] == 0 || pos[V] == 0){
			printf("ERROR: %d is not found.\n", !pos[U]?U:V);
		}
		else{
			lca(1, N, U, V);
		}
	}
} 
