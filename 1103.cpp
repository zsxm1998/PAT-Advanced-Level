#include <bits/stdc++.h>
using namespace std;
int n, k, p, maxsum = -1;
vector<int> po;//�����õ���������p�η�һ���Դ洢�������ӿ���200ms���ҵ��ٶ� 
vector<int> path, temPath;
void init(int high){
	for(int i=0; i<high; i++) po.push_back((int)pow(i, p));
}
void dfs(int index, int remain, int high){
	if(index!=k && remain<=0) return;
	if(index == k){
		if(remain != 0) return;
		int sum = accumulate(temPath.begin(), temPath.end(), 0);
		if(sum > maxsum){
			path = temPath;
			maxsum = sum;
		}
		return;
	}
	int low = 1;//low�ǵ�ǰ����С������������ǰ����С��low����������������С�ڵ��ڵ�ǰ�������һᵼ����ʽ�ĺͲ���n����Ҫ>=low 
	while(po[low]*(k-index) < remain) low++;//��k-index��low^p��Ӳ���remainʱ��low����1 
	for(int i=high; i>=low; i--){//�����Ӵ�С�������Ա�֤��������ͬ�������д�������ȳ��֣��Ӷ�������֤ͬ�����͵�����������һ���� 
		temPath.push_back(i);
		dfs(index+1, remain-po[i], i);
		temPath.pop_back();
	}
}
int main(){
	cin>>n>>k>>p;
	int high = 1;//Ѱ���������е���������high����һ��������ȡhigh��ʹn-high^p<k-1�������k-1������ȫȡ1�����У� 
	while(n - (int)pow(high, p) >= k-1) high++;//�����������������Ϊhigh-1 
	init(high);//��0~high-1��p�η����������¼��po���� 
	dfs(0, n, high-1);
	if(path.size() == 0) cout<<"Impossible";
	else{
		cout<<n<<" = ";
		for(int i=0; i<k; i++){
			if(i == 0) cout<<path[i]<<"^"<<p;
			else cout<<" + "<<path[i]<<"^"<<p;
		}
	}
	return 0;
}

/*#include <bits/stdc++.h>//��һ��ͨ���Ĵ��� 
using namespace std;
int n, k, p, maxsum = -1;
vector<int> path, temPath;
void dfs(int index, int remain, int high){
	if(index!=k && remain<=0) return;
	if(index == k){
		if(remain != 0) return;
		int sum = accumulate(temPath.begin(), temPath.end(), 0);
		if(sum > maxsum){
			path = temPath;
			maxsum = sum;
		}else if(sum == maxsum){
			bool flag = false;
			for(int i=0; i<k; i++){
				if(temPath[i] > path[i]){
					flag = true;
					break;
				}else if(temPath[i] < path[i]){
					flag = false;
					break;
				}
			}
			if(flag) path = temPath;
		}
		return;
	}
	int low = 1;
	while((int)pow(low, p)*(k-index) < remain) low++;
	for(int i=low; i<=high; i++){
		temPath.push_back(i);
		dfs(index+1, remain-(int)pow(i, p), i);
		temPath.pop_back();
	}
}
int main(){
	cin>>n>>k>>p;
	int high = 1;
	while(n - (int)pow(high, p) >= k-1) high++;
	dfs(0, n, high-1);
	if(path.size() == 0) cout<<"Impossible";
	else{
		cout<<n<<" = ";
		for(int i=0; i<k; i++){
			if(i == 0) cout<<path[i]<<"^"<<p;
			else cout<<" + "<<path[i]<<"^"<<p;
		}
	}
	return 0;
}*/
