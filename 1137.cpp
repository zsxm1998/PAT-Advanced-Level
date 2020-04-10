#include <bits/stdc++.h>
using namespace std;

struct Student{
	string id;
	int gp = -1, gm = -1, gf = -1, g = -1;
};
bool cmp(Student a, Student b){
	/*if(a.g != b.g){
		return a.g > b.g;
	}else{
		return a.id < b.id;
	}*///优化写法：
	return  a.g != b.g ? a.g > b.g : a.id < b.id;
}

int main(){
	map<string, Student> mp;
	int p, m, n;
	cin>>p>>m>>n;
	string inputId;
	int inputScore;
	for(int i=0; i<p; i++){
		cin>>inputId>>inputScore;
		mp[inputId].id = inputId;
		mp[inputId].gp = inputScore;
	}
	for(int i=0; i<m; i++){
		cin>>inputId>>inputScore;
		mp[inputId].id = inputId;
		mp[inputId].gm = inputScore;
	}
	for(int i=0; i<n; i++){
		cin>>inputId>>inputScore;
		mp[inputId].id = inputId;
		mp[inputId].gf = inputScore;
	}
	/*for(auto i : mp){
		cout<<i.second.id<<' '<<i.second.gp<<' '<<i.second.gm<<' '<<i.second.gf<<' '<<i.second.g<<endl;
	}*/
	for(auto it=mp.begin(); it!=mp.end(); it++){//①这种遍历删除的方法可以 
		if(it->second.gp < 200){
			mp.erase(it);
		}
	}
	for(auto &i : mp){
		int mid = (i.second.gm<0?0:i.second.gm), fnl = (i.second.gf<0?0:i.second.gf);
		if(mid > fnl){
			i.second.g = (int)round(mid*0.4+fnl*0.6);
		}else{
			i.second.g = fnl;
		}
	}
	auto it = mp.begin();
	while(it != mp.end()){//②这种遍历删除的方法也可以 
		if(it->second.g < 60){
			mp.erase(it++);
		}else{
			it++;
		}
	}
	vector<Student> v;
	for(auto i : mp){
		Student temp;
		temp.id = i.second.id;
		temp.gp = i.second.gp;
		temp.gm = i.second.gm;
		temp.gf = i.second.gf;
		temp.g = i.second.g;
		v.push_back(temp); 
	}
	sort(v.begin(), v.end(), cmp);
	for(auto i : v){
		cout<<i.id<<' '<<i.gp<<' '<<i.gm<<' '<<i.gf<<' '<<i.g<<endl;
	}
}
