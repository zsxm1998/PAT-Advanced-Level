#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	map<char, set<int>> mp;
	map<char, bool> stuck;
	map<char, bool> printed;
	int k, cnt = -1;
	string in;
	cin>>k>>in;
	char pre = '%';
	for(int i=0; i<=in.size(); i++){//���Ե�2��3ͨ������ԭ����ԭ���ķ���������ַ������һ���ַ� 
		if(in[i]!=pre || i==in.size()){//�Լ�ǰ�������ͬ���ַ��Ĵ��� 
			mp[pre].insert(cnt);
			pre = in[i];
			cnt = 1;
		}else{
			cnt++;
		}
	}
	for(auto it : mp){
		bool stuckFlag = true;
		for(int t : it.second){
			if(t % k != 0){
				stuckFlag = false;
				break;
			}
		}
		if(stuckFlag){
			stuck[it.first] = true;
		}
	}
	for(int i=0; i<in.size(); i++){
		if(stuck[in[i]]){
			in.erase(i+1, k-1);
			if(printed[in[i]] == false){
				cout<<in[i];
				printed[in[i]] = true;
			}
		}
	}
	cout<<endl<<in;
	return 0;
}
