/*最终通过的方法。 
 *在优化的过程中想到了使用set来优化排序复杂度，
 *但是查找的时候由于事先不知道id对应的freq故无法使用find函数查找，只能线性查找，导致3、4超时。 
 *后来由柳婼的启发，使用了fre数组存储了id对应的freq，这样就可以使用set的find函数了，减少了查找的复杂度。 
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
			//reclist.insert(item{q, ++fre[q]});//上面两句话浓缩成这一句话也正确 
		}else{
			cout<<q<<':';
			auto it = reclist.begin();
			for(int j=0; j<k && it!=reclist.end(); j++, it++){
				cout<<' '<<it->id;
			}
			cout<<endl;
			it = reclist.find(item{q, fre[q]});
			if(it != reclist.end())//如果不加这个判断会产生运行时错误 
				reclist.erase(it);
			fre[q]++;
			reclist.insert(item{q, fre[q]});
			//reclist.insert(item{q, ++fre[q]});//上面两句话浓缩成这一句话也正确 
		}
	}
}

/*改进的方法，测试点3会超时
 *使用了pos数组存储每个元素在reclist中的位置，改进了查找的时间复杂度 
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
			pos[reclist[position-1].id]++;//交换过程中要改变途径元素的pos数组，否则会出错 
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

/*最初的方法，测试点3、4会超时 
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
