#include <bits/stdc++.h>
using namespace std;

const int maxv = 1000;
vector<int> G[maxv];
int n, m, inDegree[maxv];

bool topologicalSort(vector<int> &sequence){
	int num = 0;//��¼�����������еĶ�����
	queue<int> q;
	//stack<int> q;
	for(int i=0; i<n; i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front();
		//int u = q.top();
		q.pop();
		sequence.push_back(u);//���u�������� 
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i];
			inDegree[v]--;
			if(inDegree[v] == 0){
				q.push(v);
			}
		}
		G[u].clear();//���ޱ�Ҫ�ɲ�д
		num++; 
	}
	if(num == n){//num���Բ�Ҫ����sequence.size()�ж� 
		return true;
	}else{
		return false;
	}
}

int main(){
	fill(inDegree, inDegree+maxv, 0);
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		G[u].push_back(v);
		inDegree[v]++;
	} 
	vector<int> topologicalSequence;
	if(topologicalSort(topologicalSequence)){
		for(int i : topologicalSequence){
			cout<<i<<' ';
		}
	}else{
		cout<<"�л���"; 
	} 
	return 0;
}
