#include <bits/stdc++.h>
using namespace std;
int n, l, h, exclusion = 0;
struct person{
	int id, virtue, talent, total;
	person(int i, int v, int t){
		id = i;
		virtue = v;
		talent = t;
		total = virtue + talent;
	}
	friend bool operator<(const person &a, const person &b){
		if(a.total != b.total) return a.total > b.total;
		else if(a.virtue != b.virtue) return a.virtue > b.virtue;
		else return a.id < b.id;
	}
}; 
vector<person> sage, nobleman, fool, small;
int main(){
	//if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	cin>>n>>l>>h;
	for(int i=0; i<n; i++){
		int id, virtue, talent;
		cin>>id>>virtue>>talent;
		if(virtue>=h && talent>=h){
			sage.push_back(person(id, virtue, talent));
		}else if(virtue>=h && talent<h && talent>=l){
			nobleman.push_back(person(id, virtue, talent));
		}else if(virtue>=talent && virtue<h && virtue>=l && talent<h && talent>=l){
			fool.push_back(person(id, virtue, talent));
		}else if(virtue>=l && talent>=l){
			small.push_back(person(id, virtue, talent));
		}else{
			exclusion++;
		}
	}
	cout<<setfill('0')<<n-exclusion<<endl;
	sort(sage.begin(), sage.end());
	sort(nobleman.begin(), nobleman.end());
	sort(fool.begin(), fool.end());
	sort(small.begin(), small.end());
	//cout<<"sage:----------------\n";
	for(int i=0; i<sage.size(); i++)
		cout<<setw(8)<<sage[i].id<<' '<<sage[i].virtue<<' '<<sage[i].talent<<endl;
	//cout<<"nobleman:----------------\n";
	for(int i=0; i<nobleman.size(); i++)
		cout<<setw(8)<<nobleman[i].id<<' '<<nobleman[i].virtue<<' '<<nobleman[i].talent<<endl;
	//cout<<"fool:----------------\n";
	for(int i=0; i<fool.size(); i++)
		cout<<setw(8)<<fool[i].id<<' '<<fool[i].virtue<<' '<<fool[i].talent<<endl;
	//cout<<"small:----------------\n";
	for(int i=0; i<small.size(); i++)
		cout<<setw(8)<<small[i].id<<' '<<small[i].virtue<<' '<<small[i].talent<<endl;
	return 0;
}

