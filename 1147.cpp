#include <cstdio>

using namespace std;

int M, N, flag;

void preorderjudge(int tree[], int now){
	if(now > 1 && tree[now] < tree[now/2]){
		if(flag == 0){
			flag = 1;
		}
		else if(flag == 2){
			flag = 3;
		}
	}
	else if(now > 1 && tree[now] > tree[now/2]){
		if(flag == 0){
			flag = 2;
		}
		else if(flag == 1){
			flag = 3;
		}
	}
	if(now*2 > N){
		return;
	}
	preorderjudge(tree, now*2);
	if(now*2+1 <= N){
		preorderjudge(tree, now*2+1);
	}
}

void postorderprint(int tree[], int now){
	if(now > N){
		return;
	}
	postorderprint(tree, now*2);
	postorderprint(tree, now*2+1);
	printf("%d ", tree[now]);
}

int main(){
	scanf("%d%d", &M, &N);
	int bitree[N+1];
	bitree[0] = -1;
	for(int i=0; i<M; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &bitree[j]);	
		}
		flag = 0;
		preorderjudge(bitree, 1);
		switch(flag){
			case 1:
				printf("Max Heap\n");
				break;
			case 2:
				printf("Min Heap\n");
				break;
			case 3:
				printf("Not Heap\n");
				break;
		}
		postorderprint(bitree, 2);
		postorderprint(bitree, 3);
		printf("%d\n", bitree[1]);
	}
	return 0;
} 
