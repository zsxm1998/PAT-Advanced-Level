#include <bits/stdc++.h>
using namespace std;

const int MAXV = 210;
int G[MAXV][MAXV] = {0};
int nv, ne;

bool isClique(set<int> &s){
	for(set<int>::iterator i=s.begin(); i!=s.end(); i++){
		set<int>::iterator j=i;
		for(j++; j!=s.end(); j++){
			if(!G[*i][*j]){
				return false;
			} 
		}
	}
	return true;
}

bool isMaxClique(set<int> &s){
	for(int i=1; i<=nv; i++){
		if(s.find(i) == s.end()){
			s.insert(i);
			if(isClique(s)){
				return false;
			}
			s.erase(i);
		}
	}
	return true;
}

int main(){
	cin>>nv>>ne;
	for(int i=0; i<ne; i++){
		int u, v;
		cin>>u>>v;
		G[u][v] = G[v][u] = 1;
	}
	int m;
	cin>>m;
	for(int i=0; i<m; i++){
		set<int> st;
		int k;
		cin>>k;
		for(int j=0; j<k; j++){
			int temp;
			cin>>temp;
			st.insert(temp);
		}
		if(isClique(st)){
			if(isMaxClique(st)){
				cout<<"Yes\n";
			}
			else{
				cout<<"Not Maximal\n";
			}
		}
		else{
			cout<<"Not a Clique\n";
		}
	}
}
