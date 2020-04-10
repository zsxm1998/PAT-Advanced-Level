#include <bits/stdc++.h>
using namespace std;

const int maxe = 10000;
const int maxv = 1000;
struct edge{
	int u, v, cost;
}E[maxe];

bool cmp(edge a, edge b){
	return a.cost < b.cost;
}

int father[maxv];
int findFather(int x){
	int a = x; 
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

int kruskal(int n, int m){//nΪ��������� mΪͼ�ı��� 
	int ans = 0, edgeNum = 0;//ansΪ�����Ȩ֮�ͣ�edgeNumΪ��ǰ�������ı���
	for(int i=0; i<n; i++){//���鼯��ʼ�� 
		father[i] = i;
	} 
	sort(E, E+m, cmp);
	for(int i=0; i<m; i++){
		int faU = findFather(E[i].u);
		int faV = findFather(E[i].v);
		if(faU != faV){
			father[faU] = faV;
			ans += E[i].cost;
			edgeNum++;
			if(edgeNum == n - 1) break;
		}
	}
	if(edgeNum != n - 1) return -1;//�޷���ͨʱ����-1 
	else return ans;
}

int main(){
	return 0;
}
