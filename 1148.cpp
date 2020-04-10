#include <bits/stdc++.h>
using namespace std;

int n, m=2, l=2;//输入参数 
vector<int> say, werewolf, lie;

void printWolf(){//打印狼序列 
	int i=1;
	while(werewolf[i] == 1) i++;
	cout<<i++;
	while(i<=n){
		if(werewolf[i] == -1) cout<<' '<<i;
		i++;
	}
}


bool dfs(int index, int wolfNum){
	if(wolfNum == m){//如果够了m=2头狼
		lie.clear();
		for(int i=1; i<=n; i++){//将撒谎者存入lie序列 
			if(say[i]*werewolf[abs(say[i])] < 0){
				lie.push_back(i);
			}
		}
		if(lie.size() == l){//如果有l=2个说谎者 
			int count = 0;
			for(auto li : lie){//计算撒谎的狼的个数 
				if(werewolf[li] < 0){
					count++;
				}
			}
			if(count>0 && count<m){//如果满足题目要求 
				printWolf();
				return true;
			} 
		}
		return false;
	}
	if(index == n+1) return false;//到头了却不够m=2个狼人
	werewolf[index] = -1;//当前设为狼 
	if(dfs(index+1, wolfNum+1)) return true;
	werewolf[index] = 1;//当前设为人 
	if(dfs(index+1, wolfNum)) return true;
	return false;
}

int main(){
	cin>>n;
	say.resize(n+1);
	werewolf.resize(n+1);
	for(int i=1; i<=n; i++) cin>>say[i];
	fill(werewolf.begin(), werewolf.end(), 1);//1代表人，-1代表狼 
	if(!dfs(1, 0)) cout<<"No Solution";//如果没有满足题目要求的序列 
	return 0;
}
