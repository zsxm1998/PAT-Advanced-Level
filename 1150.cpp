#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct GEdge{
	int tail, head, dist;
	GEdge* next;
	GEdge(int t, int h, int d){
		tail = t;
		head = h;
		dist = d;
		next = NULL;
	}
};

struct GVertex{
	vector<GEdge> edge; 
};

int distance(vector<GVertex> &Graph, int s, int t){
	for(vector<GEdge>::iterator it=Graph[s].edge.begin(); it!=Graph[s].edge.end(); it++){
		if(it->head == t){
			return it->dist;
		}
	}
	return -1;
}

int main(){
	vector<GVertex> Graph;
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<=N; i++){
		Graph.push_back(GVertex());
	}
	for(int i=0; i<M; i++){
		int tail, head, dist;
		scanf("%d %d %d", &tail, &head, &dist);
		Graph[tail].edge.push_back(GEdge(tail, head, dist));
		Graph[head].edge.push_back(GEdge(head, tail, dist));
		/*for(int j=1; j<=N; j++){
			if(Graph[j].edge.size() != 0){
				printf("----------------%d\n", j);
				for(vector<GEdge>::iterator it=Graph[j].edge.begin(); it!=Graph[j].edge.end(); it++){
					printf("%d-->%d\n", it->tail, it->head);
				}
			}
		}*/
	}
	int K, shortnum = 0, shortdist = 99999999;
	scanf("%d", &K);
	for(int i=1; i<=K; i++){
		int n, flag = 0, visited[N+1];//用来判断情况的变量flag一定要赋初值，否则下一次循环会保持上一次的值而导致情况判断出错 
		memset(visited, 0, sizeof(visited));
		scanf("%d", &n);
		int C[n];
		for(int j=0; j<n; j++){
			scanf("%d", &C[j]);
		}
		int sum = 0;
		for(int j=0; j<n-1; j++){
			int dis = distance(Graph, C[j], C[j+1]);
			if(dis == -1){
				flag = 3;
				break;
			}
			else{
				sum += dis;
				visited[C[j]]++;
			}
		}
		if(flag == 3){
			printf("Path %d: NA (Not a TS cycle)\n", i);
		}
		else if(C[0] != C[n-1]){
			printf("Path %d: %d (Not a TS cycle)\n", i, sum);
		}
		else{
			bool visitAllFlag = true, notSimpleFlag = false;
			for(int j=1; j<=N; j++){
				visitAllFlag = visitAllFlag && visited[j];
				notSimpleFlag = notSimpleFlag || visited[j]>1;
			}
			if(visitAllFlag){
				if(notSimpleFlag){
					printf("Path %d: %d (TS cycle)\n", i, sum);
				}
				else{
					printf("Path %d: %d (TS simple cycle)\n", i, sum);
				}
				if(sum < shortdist){
					shortnum = i;
					shortdist = sum;
				}
			}
			else{
				printf("Path %d: %d (Not a TS cycle)\n", i, sum);
			}
		}
	}
	printf("Shortest Dist(%d) = %d\n", shortnum, shortdist);
	return 0;
}
