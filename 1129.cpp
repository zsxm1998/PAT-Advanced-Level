/*����ͨ���ķ����� 
 *���Ż��Ĺ������뵽��ʹ��set���Ż������Ӷȣ�
 *���ǲ��ҵ�ʱ���������Ȳ�֪��id��Ӧ��freq���޷�ʹ��find�������ң�ֻ�����Բ��ң�����3��4��ʱ�� 
 *���������S��������ʹ����fre����洢��id��Ӧ��freq�������Ϳ���ʹ��set��find�����ˣ������˲��ҵĸ��Ӷȡ� 
 */
#include <bits/stdc++.h>
using namespace std;
struct item{
	int id, freq;
	friend bool operator<(const item &a, const item &b){
		return a.freq != b.freq ? a.freq > b.freq : a.id < b.id;
	}
};
const int MAXN = 50010;
int fre[MAXN] = {0};
int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin>>n>>k;
	set<item> reclist;
	for(int i=0; i<n; i++){
		int q;
		cin>>q;
		if(i == 0){
			fre[q]++;
			reclist.insert(item{q, fre[q]});
			//reclist.insert(item{q, ++fre[q]});//�������仰Ũ������һ�仰Ҳ��ȷ 
		}else{
			cout<<q<<':';
			auto it = reclist.begin();
			for(int j=0; j<k && it!=reclist.end(); j++, it++){
				cout<<' '<<it->id;
			}
			cout<<endl;
			it = reclist.find(item{q, fre[q]});
			if(it != reclist.end())//�����������жϻ��������ʱ���� 
				reclist.erase(it);
			fre[q]++;
			reclist.insert(item{q, fre[q]});
			//reclist.insert(item{q, ++fre[q]});//�������仰Ũ������һ�仰Ҳ��ȷ 
		}
	}
}

/*�Ľ��ķ��������Ե�3�ᳬʱ
 *ʹ����pos����洢ÿ��Ԫ����reclist�е�λ�ã��Ľ��˲��ҵ�ʱ�临�Ӷ� 
#include <bits/stdc++.h>
using namespace std;
struct item{
	int id, freq;
	friend bool operator<(const item &a, const item &b){
		return a.freq != b.freq ? a.freq > b.freq : a.id < b.id;
	}
};
vector<item> reclist;
const int MAXN = 50010;
int pos[MAXN];
int putitem(int id){
	int position;
	if(pos[id] == -1){
		reclist.push_back(item{id, 1});
		position = reclist.size() - 1;
	}else{
		position = pos[id];
		reclist[position].freq++;
	}
	for(;position > 0; position--){
		if(reclist[position] < reclist[position-1]){
			pos[reclist[position-1].id]++;//����������Ҫ�ı�;��Ԫ�ص�pos���飬�������� 
			swap(reclist[position], reclist[position-1]);
		}else{
			break;
		}
	}
	return position;
}
int main(){
	ios::sync_with_stdio(false);
	fill(pos, pos+MAXN, -1);
	int n, k;
	cin>>n>>k;
	for(int i=0; i<n; i++){
		int q;
		cin>>q;
		if(i == 0){
			pos[q] = putitem(q);
		}else{
			cout<<q<<':';
			for(int j=0; j<k && j<reclist.size(); j++){
				cout<<' '<<reclist[j].id;
			}
			cout<<endl;
			pos[q] = putitem(q);
		}
	}
}*/

/*����ķ��������Ե�3��4�ᳬʱ 
#include <bits/stdc++.h>
using namespace std;
struct item{
	int id, freq;
};
bool cmp(const item &a, const item &b){
	return a.freq != b.freq ? a.freq > b.freq : a.id < b.id;
}
int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin>>n>>k;
	vector<item> reclist;
	for(int i=0; i<n; i++){
		int q;
		cin>>q;
		if(i == 0){
			reclist.push_back(item{q, 1});
		}else{
			cout<<q<<':';
			for(int j=0; j<k && j<reclist.size(); j++){
				cout<<' '<<reclist[j].id;
			}
			cout<<endl;
			int j;
			for(j = 0; j < reclist.size(); j++){
				if(reclist[j].id == q){
					reclist[j].freq++;
					break;
				}
			}
			if(j == reclist.size()){
				reclist.push_back(item{q, 1});
			}
			for(int s=j; s>0; s--){
				if(cmp(reclist[s], reclist[s-1])){
					swap(reclist[s], reclist[s-1]);
				}else{
					break;
				}
			}
		}
	}
}*/
