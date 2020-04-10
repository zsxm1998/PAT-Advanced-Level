#include <bits/stdc++.h>
using namespace std;
int n, k, m;
struct user{
	int id, perfect = 0, total = 0, submit = 0;//submit不为0代表有题目通过了编译 
	vector<int> score; //-1代表这题没提交，0代表提交了但没过编译或过了编译但得0分 
};
bool cmp(const user &a, const user &b){//这里不加const会报错 
	if(a.total != b.total) return a.total > b.total;
	else if(a.perfect != b.perfect) return a.perfect > b.perfect;
	else return a.id < b.id;
}
int main(){
	//if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	cin>>n>>k>>m;
	vector<user> rklist(n+1);
	for(int i=1; i<=n; i++){
		rklist[i].id = i;
		rklist[i].score.resize(k+1, -1);
	} 
	vector<int> fscore(k+1);
	for(int i=1; i<=k; i++) cin>>fscore[i];
	for(int i=0; i<m; i++){
		int uid, pid, score;
		cin>>uid>>pid>>score;
		if(score==-1 && rklist[uid].score[pid]<=0)//最后一个测试点的错误出在这里，某次-1的提交可能在有效提交的后面 
			rklist[uid].score[pid] = 0;//如果不加后面的判断条件就会使前面有效提交得到的分归零 
		else if(score>rklist[uid].score[pid] || (score==0 && rklist[uid].score[pid]==0)){
			if(rklist[uid].score[pid] <= 0){
				rklist[uid].score[pid] = 0;
				rklist[uid].submit++;
			}
			rklist[uid].total += score - rklist[uid].score[pid];
			rklist[uid].score[pid] = score;
			if(score == fscore[pid])
				rklist[uid].perfect++;
		}
	}
	sort(rklist.begin()+1, rklist.end(), cmp);
	cout<<setfill('0');
	int prerk = 1, presc = rklist[1].total;
	for(int i=1; i<=n; i++){
		if(rklist[i].submit == 0) continue;//这里不要用break，否则可能后面有些提交了通过编译但得分为0的人无法打印出来 
		if(rklist[i].total == presc){
			cout<<prerk;
		}else{
			cout<<i;
			prerk = i;
			presc = rklist[i].total;
		}
		cout<<' '<<setw(5)<<rklist[i].id<<' '<<rklist[i].total;
		for(int j=1; j<=k; j++){
			if(rklist[i].score[j] == -1) cout<<" -";
			else cout<<' '<<rklist[i].score[j];
		}
		cout<<endl;
	}
	return 0;
}
/*此代码虽然通过了但有逻辑缺陷 
#include <bits/stdc++.h>
using namespace std;
int n, k, m;
struct user{
	int id, perfect = 0, total = 0, submit = 0;//submit代表通过编译的题数  
	vector<int> score; //-1代表这题没提交，0代表提交了但没过编译或过了编译但得0分 
};
bool cmp(const user &a, const user &b){//这里不加const会报错 
	if(a.total != b.total) return a.total > b.total;
	else if(a.perfect != b.perfect) return a.perfect > b.perfect;
	else return a.id < b.id;
}
int main(){
	if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	cin>>n>>k>>m;
	vector<user> rklist(n+1);
	for(int i=1; i<=n; i++){
		rklist[i].id = i;
		rklist[i].score.resize(k+1, -1);
	} 
	vector<int> fscore(k+1);
	for(int i=1; i<=k; i++) cin>>fscore[i];
	for(int i=0; i<m; i++){
		int uid, pid, score;
		cin>>uid>>pid>>score;
		if(score==-1 && rklist[uid].score[pid]<=0)//最后一个测试点的错误出在这里，某次-1的提交可能在有效提交的后面 
			rklist[uid].score[pid] = 0;//如果不加后面的判断条件就会使前面有效提交得到的分归零 
		else if(score > rklist[uid].score[pid]){//这里如果对于一道题先-1后0则submit不能正常++ 
			if(rklist[uid].score[pid] <= 0){
				rklist[uid].score[pid] = 0;
				rklist[uid].submit++;
			}
			rklist[uid].total += score - rklist[uid].score[pid];
			rklist[uid].score[pid] = score;
			if(score == fscore[pid])
				rklist[uid].perfect++;
		}
	}
	sort(rklist.begin()+1, rklist.end(), cmp);
	cout<<setfill('0');
	int prerk = 1, presc = rklist[1].total;
	for(int i=1; i<=n; i++){
		if(rklist[i].submit == 0) break;
		if(rklist[i].total == presc){
			cout<<prerk;
		}else{
			cout<<i;
			prerk = i;
			presc = rklist[i].total;
		}
		cout<<' '<<setw(5)<<rklist[i].id<<' '<<rklist[i].total;
		for(int j=1; j<=k; j++){
			if(rklist[i].score[j] == -1) cout<<" -";
			else cout<<' '<<rklist[i].score[j];
		}
		cout<<endl;
	}
	return 0;
}
*/
