#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int father[MAXN] = {0};

void init(int n){//��ʼ�����鼯 
	for(int i=0; i<n; i++) father[i] = i;
}

int findFather(int x){//�������ڼ��ϵĸ��ڵ� 
	while(x != father[x]){
		x = father[x];
	}
	return x;
} 

void Union(int a, int b){//���鼯�ϲ����� 
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB) father[faA] = faB;
}

int findFather(int x){//·��ѹ�� 
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
