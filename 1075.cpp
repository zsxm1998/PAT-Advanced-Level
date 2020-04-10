#include <bits/stdc++.h>
using namespace std;
int n, k, m;
struct user{
	int id, perfect = 0, total = 0, submit = 0;//submit��Ϊ0��������Ŀͨ���˱��� 
	vector<int> score; //-1��������û�ύ��0�����ύ�˵�û���������˱��뵫��0�� 
};
bool cmp(const user &a, const user &b){//���ﲻ��const�ᱨ�� 
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
		if(score==-1 && rklist[uid].score[pid]<=0)//���һ�����Ե�Ĵ���������ĳ��-1���ύ��������Ч�ύ�ĺ��� 
			rklist[uid].score[pid] = 0;//������Ӻ�����ж������ͻ�ʹǰ����Ч�ύ�õ��ķֹ��� 
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
		if(rklist[i].submit == 0) continue;//���ﲻҪ��break��������ܺ�����Щ�ύ��ͨ�����뵫�÷�Ϊ0�����޷���ӡ���� 
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
/*�˴�����Ȼͨ���˵����߼�ȱ�� 
#include <bits/stdc++.h>
using namespace std;
int n, k, m;
struct user{
	int id, perfect = 0, total = 0, submit = 0;//submit����ͨ�����������  
	vector<int> score; //-1��������û�ύ��0�����ύ�˵�û���������˱��뵫��0�� 
};
bool cmp(const user &a, const user &b){//���ﲻ��const�ᱨ�� 
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
		if(score==-1 && rklist[uid].score[pid]<=0)//���һ�����Ե�Ĵ���������ĳ��-1���ύ��������Ч�ύ�ĺ��� 
			rklist[uid].score[pid] = 0;//������Ӻ�����ж������ͻ�ʹǰ����Ч�ύ�õ��ķֹ��� 
		else if(score > rklist[uid].score[pid]){//�����������һ������-1��0��submit��������++ 
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
