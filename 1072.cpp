#include <bits/stdc++.h>
using namespace std;

const int maxv = 1100;//题目说是小于等于10^3但不能设为120，否则最后一个测试点段错误，设为1000最后一个测试点答案错误 
const int inf = 0x3fffffff;
int n, m, k, ds;

int stringtoint(string s){
	if(s[0] == 'G'){
		return n + stoi(s.substr(1));
	}else{
		return stoi(s);
	}
}

string inttostring(int i){
	if(i > n){
		string s1 = "G";
		string s2 = to_string(i - n);
		return s1 + s2;
	}else{
		return to_string(i);
	}
}

int G[maxv][maxv];
bool vis[maxv] = {false};
int d[20][maxv];

void Dijkstra(int s){
	int x = s - n;
	fill(d[x], d[x]+maxv, inf);
	fill(vis, vis+maxv, false);
	d[x][s] = 0;
	for(int i=1; i<=n+m; i++){
		int u = -1, min = inf;
		for(int j=1; j<=n+m; j++){
			if(!vis[j] && d[x][j]<min){
				u = j;
				min = d[x][j];
			}
		} 
		if(u == -1) return;
		vis[u] = true;
		for(int v=1; v<=n+m; v++){
			if(!vis[v] && G[u][v]!=inf && d[x][u]+G[u][v]<d[x][v]){
				d[x][v] = d[x][u] + G[u][v];
			}
		}
	}
}

vector<int> satisfied;

int minDistance(int x){
	int min = inf;
	for(int i=1; i<=n; i++){
		if(d[x][i] < min){
			min = d[x][i];
		}
	}
	return min;
}

int selectAnswer(){
	for(int i=1; i<=m; i++){
		bool flag = true;
		for(int j=1; j<=n; j++){
			if(d[i][j] > ds){
				flag = false;
				break;
			}
		}
		if(flag){
			satisfied.push_back(i);
		}
	}
	if(satisfied.size() == 0){
		return -1;
	}else if(satisfied.size() == 1){
		return satisfied[0] + n;
	}
	vector<int> tempSatis;
	int far = -1;
	for(auto i : satisfied){
		int mindis = minDistance(i);
		if(mindis > far){
			far = mindis;
			tempSatis.clear();
			tempSatis.push_back(i);
		}else if(mindis == far){
			tempSatis.push_back(i);
		}
	}
	satisfied = tempSatis;
	if(satisfied.size() == 1){
		return satisfied[0] + n;
	}
	double minavg = inf;
	for(auto i : satisfied){
		double avg = 0;
		for(int j=1; j<=n; j++){
			avg += d[i][j];
		}
		avg /= n;
		if(avg < minavg){
			minavg = avg;
			tempSatis.clear();
			tempSatis.push_back(i);
		}else if(avg == minavg){
			tempSatis.push_back(i);
		}
	}
	return tempSatis[0] + n;
}

int main(){
	ios::sync_with_stdio(false);
	fill(G[0], G[0]+maxv*maxv, inf);//主函数最开始要对图初始化 
	cin>>n>>m>>k>>ds;
	for(int i=0; i<k; i++){
		int dist, u, v;
		string p1, p2;
		cin>>p1>>p2>>dist;
		u = stringtoint(p1);
		v = stringtoint(p2);
		G[u][v] = G[v][u] = dist;
	}
	for(int i=1; i<=m; i++){
		Dijkstra(n + i);
	}
	int answer = selectAnswer();
	if(answer == -1){
		cout<<"No Solution";
	}else{
		cout<<inttostring(answer)<<endl;
		double minimum = inf, average = 0;
		int x = answer - n;
		for(int i=1; i<=n; i++){
			average += d[x][i];
			if(d[x][i] < minimum){
				minimum = d[x][i];
			}
		}
		average /= n;
		cout<<fixed<<setprecision(1)<<minimum<<' '<<round(average*10)/10;
	}
} 
