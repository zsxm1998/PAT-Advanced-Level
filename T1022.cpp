#include <bits/stdc++.h>
using namespace std;

int n, m, l;
vector<int> say, werewolf, lie;

void printWolf(){
	int i=n;
	while(werewolf[i] == 1) i--;
	cout<<i--;
	while(i>0){
		if(werewolf[i] == -1) cout<<' '<<i;
		i--;
	}
}


bool dfs(int index, int wolfNum){
	if(wolfNum == m){//如果够了m头狼
		lie.clear();
		for(int i=1; i<=n; i++){
			if(say[i]*werewolf[abs(say[i])] < 0){
				lie.push_back(i);
			}
		}
		if(lie.size() == l){//如果有l个说谎者 
			int count = 0;
			for(auto li : lie){
				if(werewolf[li] < 0){
					count++;
				}
			}
			if(count>0 && count<m){
				printWolf();
				return true;
			} 
		}
		return false;
	}
	if(index == 0) return false;//到头了却不够m个狼人
	werewolf[index] = -1;
	if(dfs(index-1, wolfNum+1)) return true;
	werewolf[index] = 1;
	if(dfs(index-1, wolfNum)) return true;
	return false;
}

int main(){
	cin>>n>>m>>l;
	say.resize(n+1);
	werewolf.resize(n+1);
	for(int i=1; i<=n; i++) cin>>say[i];
	fill(werewolf.begin(), werewolf.end(), 1);
	if(!dfs(n, 0)) cout<<"No Solution";
	return 0;
}
