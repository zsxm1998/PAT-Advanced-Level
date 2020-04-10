#include <bits/stdc++.h>
using namespace std;

int n, m=2, l=2;//������� 
vector<int> say, werewolf, lie;

void printWolf(){//��ӡ������ 
	int i=1;
	while(werewolf[i] == 1) i++;
	cout<<i++;
	while(i<=n){
		if(werewolf[i] == -1) cout<<' '<<i;
		i++;
	}
}


bool dfs(int index, int wolfNum){
	if(wolfNum == m){//�������m=2ͷ��
		lie.clear();
		for(int i=1; i<=n; i++){//�������ߴ���lie���� 
			if(say[i]*werewolf[abs(say[i])] < 0){
				lie.push_back(i);
			}
		}
		if(lie.size() == l){//�����l=2��˵���� 
			int count = 0;
			for(auto li : lie){//�������ѵ��ǵĸ��� 
				if(werewolf[li] < 0){
					count++;
				}
			}
			if(count>0 && count<m){//���������ĿҪ�� 
				printWolf();
				return true;
			} 
		}
		return false;
	}
	if(index == n+1) return false;//��ͷ��ȴ����m=2������
	werewolf[index] = -1;//��ǰ��Ϊ�� 
	if(dfs(index+1, wolfNum+1)) return true;
	werewolf[index] = 1;//��ǰ��Ϊ�� 
	if(dfs(index+1, wolfNum)) return true;
	return false;
}

int main(){
	cin>>n;
	say.resize(n+1);
	werewolf.resize(n+1);
	for(int i=1; i<=n; i++) cin>>say[i];
	fill(werewolf.begin(), werewolf.end(), 1);//1�����ˣ�-1������ 
	if(!dfs(1, 0)) cout<<"No Solution";//���û��������ĿҪ������� 
	return 0;
}
