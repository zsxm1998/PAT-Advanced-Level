#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int father[MAXN] = {0};

void init(int n){//初始化并查集 
	for(int i=0; i<n; i++) father[i] = i;
}

int findFather(int x){//查找所在集合的根节点 
	while(x != father[x]){
		x = father[x];
	}
	return x;
} 

void Union(int a, int b){//并查集合并操作 
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB) father[faA] = faB;
}

int findFather(int x){//路径压缩 
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

int main(){
	return 0;
} 
