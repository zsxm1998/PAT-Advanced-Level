#include <bits/stdc++.h>
using namespace std;
//int matrix[100][100];
int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int N, m, n;
	cin>>N;
	vector<int> in(N);
	for(int i=sqrt(N); i>0; i--){
		if(N % i == 0){
			m = N / i;
			n = i;
			break;
		}
	}
	vector<vector<int>> matrix(m, vector<int>(n));
	for(int i=0; i<N; i++){
		cin>>in[i];
	}
	sort(in.begin(), in.end(), greater<int>());
	int left = 0, up = 0, right = n-1, down = m-1;
	int flag = 1;//1¡ú 2¡ý 3¡û 4¡ü 
	int i = 0, j = 0;
	for(int t=0; t<N; t++){
		matrix[i][j] = in[t];
		if(flag == 1){
			if(j == right){
				i++;
				flag = 2;
				up++;
			}else{
				j++;
			}
		}else if(flag == 2){
			if(i == down){
				j--;
				flag = 3;
				right--;
			}else{
				i++;
			}
		}else if(flag == 3){
			if(j == left){
				i--;
				flag = 4;
				down--;
			}else{
				j--;
			}
		}else if(flag == 4){
			if(i == up){
				j++;
				flag = 1;
				left++;
			}else{
				i--;
			}
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout<<matrix[i][j]<<(j+1==n?'\n':' ');
		}
	}
	return 0;
}

