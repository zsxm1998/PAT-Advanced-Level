//这个题先按年龄排序然后再在给定年龄范围内用钱排序，会导致排序次数过多，时间复杂度过高，测试点2超时
//应该先整体按钱排序，然后给定年龄范围时从头到尾遍历输入，符合年龄范围的就输出，并且输出数目够了就结束 
#include <bits/stdc++.h>
using namespace std;
struct person{
	string name;
	int age, worth;
};
bool cmpByWorth(const person &a, const person &b){
	if(a.worth != b.worth) return a.worth > b.worth;
	else if(a.age != b.age) return a.age < b.age;
	else return a.name < b.name;
}
int main(){
	if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	int n, k;
	cin>>n>>k;
	vector<person> input(n);
	for(int i=0; i<n; i++){
		cin>>input[i].name>>input[i].age>>input[i].worth;
	}
	sort(input.begin(), input.end(), cmpByWorth);
	for(int i=1; i<=k; i++){
		int m, amin, amax, cnt = 0;
		cin>>m>>amin>>amax;
		cout<<"Case #"<<i<<":\n";
		for(int i=0; i<n&&cnt<m; i++){
			if(input[i].age>=amin && input[i].age<=amax){
				cout<<input[i].name<<' '<<input[i].age<<' '<<input[i].worth<<endl;
				cnt++;
			}
		}
		if(cnt == 0) cout<<"None\n";
	}
	return 0;
}
/*测试点2超时 
#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int c[210] = {0}, Amin[210] = {0}, Amax[210] = {0};
void update(int x, int v){
	for(; x<=200; x+=lowbit(x))
		c[x] += v;
}
int getsum(int x){
	int sum = 0;
	for(; x>0; x-=lowbit(x))
		sum += c[x];
	return sum;
}
struct person{
	string name;
	int age, worth;
};
bool cmpByAge(const person &a, const person &b){
	return a.age < b.age;
}
bool cmpByWorth(const person &a, const person &b){
	if(a.worth != b.worth) return a.worth > b.worth;
	else if(a.age != b.age) return a.age < b.age;
	else return a.name < b.name;
}
int main(){
	if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	int n, k;
	cin>>n>>k;
	vector<person> input(n);
	for(int i=0; i<n; i++){
		cin>>input[i].name>>input[i].age>>input[i].worth;
		update(input[i].age, 1);
	}
	sort(input.begin(), input.end(), cmpByAge);
	for(int i=0; i<201; i++){
		Amin[i+1] = Amax[i] = getsum(i);
	}
	for(int i=1; i<=k; i++){
		int m, amin, amax;
		cin>>m>>amin>>amax;
		int l = Amin[amin], r = Amax[amax];
		cout<<"Case #"<<i<<":\n";
		if(m==0 || l>=r) cout<<"None\n";
		else{
			vector<person> output;
			for(int t=l; t<r; t++){
				output.push_back(input[t]);
			}
			sort(output.begin(), output.end(), cmpByWorth);
			for(int t=0; t<m && t<output.size(); t++){
				cout<<output[t].name<<' '<<output[t].age<<' '<<output[t].worth<<endl;
			}
		}
	}
	return 0;
}
*/

