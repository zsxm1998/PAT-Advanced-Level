#include <cstdio>
#include <vector>

using namespace std;

struct Node{
	int data;
	Node* lchild;
	Node* rchild;
	Node* parent;
};

vector<int> pre, in;

Node* createTreeFromPreAndIn(int preL, int preR, int inL, int inR, Node* parent){
	if(preL > preR){
		return NULL;
	}
	Node* root = new Node;
	root->data = pre[preL];
	int k;
	for(k=inL; k<=inR; k++){
		if(pre[preL] == in[k]){
			break;
		}
	}
	int leftTreeNum = k - inL;
	root->lchild = createTreeFromPreAndIn(preL+1, preL+leftTreeNum, inL, k-1, root);
	root->rchild = createTreeFromPreAndIn(preL+leftTreeNum+1, preR, k+1, inR, root);
	root->parent = parent;
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
	for(int i=0; i<N; i++){
		int tmp;
		scanf("%d", &tmp);
		in.push_back(tmp);
	}
	for(int i=0; i<N; i++){
		int tmp;
		scanf("%d", &tmp);
		pre.push_back(tmp);
	}
	Node* bitree = createTreeFromPreAndIn(0, pre.size()-1, 0, in.size()-1, NULL);
	for(int i=0; i<M; i++){
		int U, V, flag = 0;
		scanf("%d%d", &U, &V);
		vector<int> pathU;
		if(postorder(bitree, pathU, U)){
			flag += 1;
		}
		vector<int> pathV;
		if(postorder(bitree, pathV, V)){
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
}
