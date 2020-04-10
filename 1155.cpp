#include <cstdio>
#include <vector>

using namespace std;

int N;
int flag = 0;

void preorder(int tree[], int now, vector<int> &path){
	path.push_back(now);
	if(path.size()>1 && tree[now] < tree[now/2]){
		if(flag == 0){
			flag = 1;
		}
		else if(flag == 2){
			flag = 3;
		}
	}
	else if(path.size()>1 && tree[now] > tree[now/2]){
		if(flag == 0){
			flag = 2;
		}
		else if(flag == 1){
			flag = 3;
		}
	}
	if(now*2 > N){
		for(int i=0; i<path.size();i++){
			printf("%d", tree[path[i]]);
			if(i != path.size()-1){
				printf(" ");
			}
		}
		printf("\n");
		path.pop_back();
		return;
	}
	if(now*2+1 <= N){
		preorder(tree, now*2+1, path);
	}
	preorder(tree, now*2, path);
	path.pop_back();
}

int main(){
	scanf("%d", &N);
	int bitree[N+1];
	bitree[0] = -1;
	for(int i=1; i<=N; i++){
		scanf("%d", &bitree[i]);
	}
	vector<int> path;
	preorder(bitree, 1, path);
	switch(flag){
		case 1:
			printf("Max Heap");
			break;
		case 2:
			printf("Min Heap");
			break;
		case 3:
			printf("Not Heap");
			break;
	}
	return 0;
} 
