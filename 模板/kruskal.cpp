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

int kruskal(int n, int m){//n为顶点个数， m为图的边数 
	int ans = 0, edgeNum = 0;//ans为所求边权之和，edgeNum为当前生成树的边数
	for(int i=0; i<n; i++){//并查集初始化 
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
	if(edgeNum != n - 1) return -1;//无法连通时返回-1 
	else return ans;
}

int main(){
	return 0;
}
