#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
vector<int> seq, pos;//seq为序列，pos[i]为i在seq中的位置 
void Swap(int x){
	swap(seq[pos[0]], seq[pos[x]]);//在seq中交换0和x 
	swap(pos[0], pos[x]);//交换0和x的位置 
	cnt++;//调用Swap次数加1 
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	seq.resize(n);
	pos.resize(n);
	for(int i=0; i<n; i++){
		cin>>seq[i];
		pos[seq[i]] = i;
	} 
	int t=0;//这里t等于1也可以，因为开始用到t时pos[0]一定等于0，故0一定会被跳过 
	do{//位置正确的数一定不会再被交换，因为Swap交换的是0和位置不正确的数 
		while(pos[0] != 0) Swap(pos[0]);//当0的位置不是0时交换0和0的位置对应的数，会让一个数归位 
		//t = 0;//注释掉这句话是优化超时的关键，之前检测过的t不用再检测了，位置肯定正确，因为位置正确的数不会被交换，注释掉这句话可以将时间复杂度降低到线性 
		while(t<n && pos[t]==t) t++;//这里pos可以用seq代替，和下一行的三种选择共六种组合都正确；这里不用担心t在下次循环中没有归位，因为下次检测还是从t开始，若t没有归位则还可以继续把0移出来 
		if(t != n) Swap(t);//这里右边的t可以用seq[t]或pos[t]代替 
	}while(t < n);
	cout<<cnt;
	return 0;
}

