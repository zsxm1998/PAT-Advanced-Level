#include <bits/stdc++.h>
using namespace std;

const int maxv = 1000;
int n, m;//nΪ�ڵ�����mΪ���� 
int inDegree[maxv], ve[maxv], vl[maxv];
struct node{
	int v, len, num;//vΪ���յ㣬lenΪ�߳���numΪ�ߣ�����ı�� 
	node(int vv, int ll, int nn){
		v = vv;
		len = ll;
		num = nn;
	}
};
vector<node> G[maxv];//�ڽӱ�洢��ͼ 
stack<int> topOrder;
bool topologicalSort(){
	queue<int> q;
	for(int i=0; i<n; i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		topOrder.push(u);
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i].v, len = G[u][i].len;
			inDegree[v]--;
			if(inDegree[v] == 0){
				q.push(v);
			}
			if(ve[u] + len > ve[v]){
				ve[v] = ve[u] + len;
			}
		}
	}
	if(topOrder.size() == n) return true;
	else return false;
}
int criticalPath(){
	memset(ve, 0, sizeof(ve));//��ʼ������ve 
	if(topologicalSort() == false){//��������˳��ȷ��ve 
		return -1;//���������޻�ͼ������-1 
	}
	//fill(vl, vl+maxv, ve[n-1]);//vl�����ʼ������ʼֵΪ����veֵ ,�㷨�ʼǸ�������� 
	int destination = topOrder.top();//���߿���ͨ����ve�����е����ֵ����ȡ���ı�� 
	fill(vl, vl+maxv, ve[destination]);//vl�����ʼ������ʼֵΪ����veֵ 
	while(!topOrder.empty()){//ͨ������������������vl 
		int u = topOrder.top();
		topOrder.pop();
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i].v, len = G[u][i].len;
			if(vl[v] - len < vl[u]){
				vl[u] = vl[v] - len;
			}
		}
	}
	//�����ڽӱ����еıߣ����������翪ʼʱ��e����ٿ�ʼʱ��l 
	for(int u=0; u<n; u++){
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i].v, len = G[u][i].len;
			int e = ve[u], l = vl[v] - len;
			if(e == l){//e == l˵���ǹؼ��
				cout<<u<<"->"<<v<<" : "<<G[u][i].num<<endl;
			}
		}
	}
	//return ve[n-1];//���عؼ�·�����ȣ��㷨�ʼǸ�������� 
	return ve[destination];//���عؼ�·������
}

int main(){
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u, v, len;
		cin>>u>>v>>len;
		G[u].push_back(node(v, len, i));
	}
	int length = criticalPath();
	if(length == -1){
		cout<<"����DAGͼ"; 
	}else{
		cout<<"�ؼ�·���ĳ����ǣ�"<<length; 
	}
}
