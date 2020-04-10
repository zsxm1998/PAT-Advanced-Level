#include <bits/stdc++.h>
using namespace std;
int n, k, p, maxsum = -1;
vector<int> po;//将能用到的因数的p次方一次性存储起来，加快了200ms左右的速度 
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
	int low = 1;//low是当前的最小的因数，若当前因数小于low，则后面的因数都会小于等于当前因数，且会导致因式的和不够n，故要>=low 
	while(po[low]*(k-index) < remain) low++;//当k-index个low^p相加不够remain时，low增加1 
	for(int i=high; i>=low; i--){//因数从大到小遍历可以保证因数和相同的序列中大的序列先出现，从而避免验证同因数和的两个序列哪一个大 
		temPath.push_back(i);
		dfs(index+1, remain-po[i], i);
		temPath.pop_back();
	}
}
int main(){
	cin>>n>>k>>p;
	int high = 1;//寻找整个序列的最大的因数high，第一个因数若取high，使n-high^p<k-1，则后面k-1个因数全取1都不行， 
	while(n - (int)pow(high, p) >= k-1) high++;//故整个序列最大因数为high-1 
	init(high);//将0~high-1的p次方算出来并记录在po数组 
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

/*#include <bits/stdc++.h>//第一次通过的代码 
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
