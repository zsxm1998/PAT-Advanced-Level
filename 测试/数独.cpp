#include <bits/stdc++.h>//下面有速度更快的算法, 使用的是逐个点进行递归 
using namespace std;

int inputMatrix[9][9] = {0};
int outputMatrix[1000][9][9] = {0}, solutionNum = 0;
int tempMatrix[9][9] = {0};
bool checkPalace(int row, int column){
	int n = row + 3, m = column + 3;
	bool has[10] = {false};
	for(int i=row; i<n; i++){
		for(int j=column; j<m; j++){
			has[tempMatrix[i][j]] = true;
		}
	}
	bool flag = true;
	for(int i=1; i<=9; i++){
		if(!has[i]){
			flag = false;
			break;
		}
	}
	return flag;
}
bool checkColumn(int column){
	bool has[10] = {false};
	for(int i=0; i<9; i++){
		has[tempMatrix[i][column]] = true;
	}
	bool flag = true;
	for(int i=1; i<=9; i++){
		if(!has[i]){
			flag = false;
			break;
		}
	}
	return flag;
}
bool checkColumn(int column, int row){
	set<int> s;
	for(int i=0; i<row; i++){
		s.insert(tempMatrix[i][column]);
	}
	if(s.size() == row){
		return true;
	}else{
		return false;
	}
}
void sudoku(int row){
	for(int i=0; i<9; i++){
		if(!checkColumn(i, row)) return;
	}
	if(row!=0 && row%3==0){
		for(int i=0; i<9; i+=3){
			if(!checkPalace(row-3, i)) return;
		}
		if(row == 9){
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					outputMatrix[solutionNum][i][j] = tempMatrix[i][j];
				}
			}
			solutionNum++;
			return;
		}
	}
	bool has[10] = {false};
	for(int i=0; i<9; i++){
		has[inputMatrix[row][i]] = true;
	}
	vector<int> notHas;
	for(int i=1; i<=9; i++){
		if(!has[i]) notHas.push_back(i);
	}
	do{
		int lackNum = 0;
		for(int i=0; i<9; i++){
			if(inputMatrix[row][i] == 0) tempMatrix[row][i] = notHas[lackNum++];
		}
		sudoku(row+1);
	}while(next_permutation(notHas.begin(), notHas.end()));
}

int main(){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin>>inputMatrix[i][j];
			tempMatrix[i][j] = inputMatrix[i][j];
		}
	}
	sudoku(0);
	cout<<"答案一共有 "<<solutionNum<<" 种："<<endl;
	for(int k=0; k<solutionNum; k++){
		cout<<"------------------"<<endl;
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				cout<<outputMatrix[k][i][j]<<(j==8?'\n':' ');
			}
		}
	}
}
/*
#include <iostream>
using namespace std;

bool is_writen(int **sudo, int v, int k)
{
    for(int i = 0; i < 9; i++)
    {
        if(i != (v%9) && sudo[v/9][i] == k)
            return false;
    }
    for(int i = 0; i < 9; i++)
    {
        if(i != (v/9) && sudo[i][v%9] == k)
            return false;
    }
    int a = v/9, b = v%9;
    for(int i = 0; i < 3*3; i++)
    {
        if(!(((a/3*3 + i/3) == a) && ((b/3*3 + i%3) == b)) && sudo[a/3*3 + i/3][b/3*3 + i%3] == k)
            return false;
    }
    return true;
}

void dfs(int **sudo, int v)
{
    if(v == 81)
    {
        cout << "solution:" << endl;
        for(int i = 0; i < 9*9; i++)
        {
            if(i%9 == 0)
            {
                if(i == 0)
                    cout << sudo[i/9][i%9];
                else
                    cout << "\n" << sudo[i/9][i%9];
            } else {
                cout << " " << sudo[i/9][i%9];
            }
        }
        cout << endl;
        return;
    }
    if(sudo[v/9][v%9] == 0)
    {
        for(int i = 1; i < 10; i++)
        {
            if(is_writen(sudo, v, i))
            {
                sudo[v/9][v%9] = i;
                dfs(sudo, v+1);
                sudo[v/9][v%9] = 0;//还原状态 
            }
        }
    } else {
        dfs(sudo, v+1);
    }
}
void test1()
{
    int **sudo = new int*[9];
    for(int i = 0; i < 9; i++)
    {
        sudo[i] = new int[9];
    }
    for(int i = 0; i < 9*9; i++)
    {
        cin >> sudo[i/9][i%9];
    }
    dfs(sudo, 0);

    for(int i = 0; i < 9; i++)
    {
        delete sudo[i];
        sudo[i] = 0;
    }
    delete [] sudo;
    sudo = 0;
}

int main()
{
    test1();
    return 0;
}
*/
