#include <cstdio>
#include <set>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct GEdge{
	int tail, head;
	GEdge* next;
};

struct GVertex{
	int color;
	GEdge* first;
};

bool BFS(vector<GVertex> &G){
	queue<int> q;
	int visited[G.size()];
	memset(visited, 0, sizeof(visited));
	q.push(0);
	visited[0] = 1;
	while(q.size() != 0){
		int temp = q.front();
		q.pop();
		for(GEdge* i=G[temp].first; i!=NULL; i=i->next){
			if(G[temp].color == G[i->head].color){
				return false;
			}
			if(visited[i->head] == 0){
				q.push(i->head);
				visited[i->head] = 1;
			}
		}
	}
	return true;
}

int main(){
	vector<GVertex> Graph;
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		Graph.push_back(GVertex());
	}
	for(int i=0; i<M; i++){
		int t, h;
		scanf("%d %d", &t, &h);
		GEdge* p1=Graph[t].first;
		if(p1 == NULL){
			GEdge* temp = new GEdge;
			temp->tail = t;
			temp->head = h;
			temp->next = NULL;
			Graph[t].first = temp;
		}
		else{
			while(p1->next != NULL){
				p1=p1->next;
			}
			GEdge* temp = new GEdge;
			temp->tail = t;
			temp->head = h;
			temp->next = NULL;
			p1->next = temp;
		}
		GEdge* p2=Graph[h].first;
		if(p2 == NULL){
			GEdge* temp = new GEdge;
			temp->tail = h;
			temp->head = t;
			temp->next = NULL;
			Graph[h].first = temp;
		}
		else{
			while(p2->next != NULL){
				p2=p2->next;
			}
			GEdge* temp = new GEdge;
			temp->tail = h;
			temp->head = t;
			temp->next = NULL;
			p2->next = temp;
		}
	}
	int K;
	scanf("%d", &K);
	for(int i=0; i<K; i++){
		set<int> color;
		for(int j=0; j<N; j++){
			int temp;
			scanf("%d", &temp);
			color.insert(temp);
			Graph[j].color = temp;
		}
		if(BFS(Graph)){
			printf("%d", color.size());
			printf("-coloring");
			if(i != K-1){
				printf("\n");
			}
		}
		else{
			printf("No");
			if(i != K-1){
				printf("\n");
			}
		}
	}
	return 0;
}
