#include <bits/stdc++.h>
using namespace std;

const int maxv = 200;
const int inf = 0x3fffffff;
int n, m;
struct Node{
	int v, dis;
};
vector<Node> Adj[maxv];
int d[maxv], num[maxv];
vector<int> pre[maxv];
bool Bellman_Ford(int s){
	//��ʼ������ 
	fill(d, d+maxv, inf);
	memset(num, 0, sizeof(num));
	d[s] = 0;
	num[s] = 1;//������㷨num�������·���� 
	//�������d���֣�ѭ��n-1��
	for(int i=0; i<n-1; i++){
		for(int u=0; u<n; u++){
			for(int j=0; j<Adj[u].size(); j++){
				int v = Adj[u][j].v, dis = Adj[u][j].dis;
				if(d[u] + dis < d[v]){
					d[v] = d[u] + dis;
					pre[v].clear();
					pre[v].push_back(u);
					num[v] = num[u];
				}else if(d[u] + dis == d[v]){
					pre[v].push_back(u);//��仰Ҫ�������漸�仰��ǰ�� 
					num[v] = 0;//������ڼ������·��������Dijkstra��ͬ��Ҫ��պ����¼��� 
					for(int it : pre[v]){
						num[v] += num[it];
					}
				}
			}
		}
	} 
	//�жϸ����Ĳ���
	for(int u=0; u<n; u++){
		for(int j=0; j<Adj[u].size(); j++){
			int v = Adj[u][j].v, dis = Adj[u][j].dis;
			if(d[u] + dis < d[v]){
				return false;
			}
		}
	}
	return true;
} 

bool inq[maxv] = {false};
bool SPFA(int s){
	//��ʼ������ 
	fill(d, d+maxv, inf);
	memset(num, 0, sizeof(num));
	memset(inq, false, sizeof(inq));
	//Դ����Ӳ���
	queue<int> q;
	q.push(s);
	inq[s] = true;
	num[s]++;//������㷨��num����ڵ���Ӵ���
	d[s] = 0; 
	//���岿�� 
	while(!q.empty()){
		int u = q.front();
		q.pop();
		inq[u] = false;
		for(int i=0; i<Adj[u].size(); i++){
			int v = Adj[u][i].v, dis = Adj[u][i].dis;
			if(d[u] + dis < d[v]){
				d[v] = d[u] + dis;
				if(!inq[v]){
					q.push(v);
					inq[v] = true;
					num[v]++;
					if(num[v] >= n){
						return false;//�пɴ︺�� 
					}
				}
			}
		}
	}
	return true;//�޿ɴ︺�� 
}

int dis[maxv][maxv];
int path[maxv][maxv];//i->j���·����j��ǰ���ڵ� 
void Floyd(){
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(dis[i][k]!=inf && dis[k][j]!=inf && dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}
void printPath(int s, int d){
	if(path[s][d] == -1){
		cout<<"û��·����";
		return;
	}
	if(path[s][d] == s){
		cout<<s<<' '<<d;
		return; 
	}else{
		printPath(s, path[s][d]);
		cout<<' '<<d;
		return;
	}
}

int main(){//�����������Floyd�㷨 
	//��ʼ�� 
	fill(dis[0], dis[0]+maxv*maxv, inf);
	fill(path[0], path[0]+maxv*maxv, -1);
	cout<<"���붥�����ͱ�����" ; 
	cin>>n>>m;
	for(int i=0; i<n; i++){
		dis[i][i] = 0;
		path[i][i] = i;
	} 
	//��¼�� 
	int u, v, w;
	for(int i=0; i<m; i++){
		cout<<"�����"<<i+1<<"���ߵ���㡢�յ㡢�߳���"; 
		cin>>u>>v>>w;
		dis[u][v] = w;
		dis[v][u] = w;//����ͼ��û����仰 
		path[u][v] = u;
		path[v][u] = v;//����ͼ��û����仰 
	}
	//Floyd
	Floyd();
	while(1){
		int start, destination;
		cout<<"����Ҫ��ѯ·���������յ㣨����-1�˳����򣩣�";
		cin>>start;
		if(start == -1){
			break;
		}
		cin>>destination;
		printPath(start, destination);
		cout<<endl;
	} 
	return 0; 
}
