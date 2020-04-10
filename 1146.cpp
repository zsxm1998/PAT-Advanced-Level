#include <cstdio>
 
int graph[1001][1001] = {0};

int main(){
	int N, M;
	scanf("%d%d", &N, &M);
	for(int i=0; i<M; i++){
		int tail, head;
		scanf("%d%d", &tail, &head);
		graph[tail][head] = 1;
	}
	int K;
	scanf("%d", &K);
	bool firstoutput = true;
	for(int i=0; i<K; i++){
		int permutation[N];
		for(int j=0; j<N; j++){
			scanf("%d", &permutation[j]);
		}
		bool flag = true;
		for(int j=0; j<N && flag; j++){
			for(int k=j+1; k<N && flag; k++){
				if(graph[permutation[k]][permutation[j]] == 1){
					if(!firstoutput){
						printf(" ");
					}
					else{
						firstoutput = false;
					}
					printf("%d", i);
					flag = false;
				}
			}
		}
	}
	return 0;
}
