#include <bits/stdc++.h>
using namespace std;
int m, n, l, t, sum = 0;//m是行，n是列，l是层 
int matrix[1286][128][60];
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
struct coordinate{
	int x, y, z;//x是行，y是列，x是层 
	coordinate(int xx, int yy, int zz){
		x = xx;
		y = yy; 
		z = zz;
	}
};
void bfs(int x, int y, int z){
	int cnt = 0;
	queue<coordinate> q;
	q.push(coordinate(x, y, z));
	matrix[x][y][z] = 0;
	while(!q.empty()){
		coordinate u = q.front();
		q.pop();
		cnt++;
		for(int i=0; i<6; i++){
			x = u.x + dx[i];
			y = u.y + dy[i];
			z = u.z + dz[i];
			if(x>=0&&x<m && y>=0&&y<n && z>=0&&z<l && matrix[x][y][z]==1){
				q.push(coordinate(x, y, z));
				matrix[x][y][z] = 0;
			}
		}
	}
	if(cnt >= t) sum += cnt;
}
int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin>>m>>n>>l>>t;
	for(int i=0; i<l; i++)
		for(int j=0; j<m; j++)
			for(int k=0; k<n; k++) cin>>matrix[j][k][i];
	for(int i=0; i<l; i++)
		for(int j=0; j<m; j++)
			for(int k=0; k<n; k++){
				if(matrix[j][k][i] == 1) bfs(j, k, i);
			}
	cout<<sum;
	return 0;
}

