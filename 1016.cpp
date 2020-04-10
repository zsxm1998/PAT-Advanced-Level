//这道题当一个人的账单金额为0时不输出这个人，故不能采用边计算边输出的方式
//通过给这道题debug，我要记住在循环里再定义循环时循环变量一定不能和外层循环相同 
#include <bits/stdc++.h>
using namespace std;
int rate[24], n, month;
struct record{
	string name;
	int time, type;//online为1、off-line为0 
};
bool cmp(const record &a, const record &b){
	return a.name!=b.name?a.name<b.name:a.time<b.time;
}
struct charge{
	int sd, sh, sm, ed, eh, em, minute;
	double fee;
	charge(int a, int b, int c, int d, int e, int f, int g, double h){
		sd = a;
		sh = b;
		sm = c;
		ed = d;
		eh = e;
		em = f;
		minute = g; 
		fee = h;
	}
};
struct person{
	string name;
	vector<charge> bill;
	double totalfee = 0.0;
};
int main(){
	ios::sync_with_stdio(false);
	for(int i=0; i<24; i++) cin>>rate[i];
	cin>>n;
	vector<record> r(n);
	vector<person> plist;
	for(int i=0; i<n; i++){
		string type;
		char t;
		int dd, hh, mm;
		cin>>r[i].name>>month>>t>>dd>>t>>hh>>t>>mm>>type;
		r[i].time = dd*1440 + hh*60 + mm;
		r[i].type = type=="on-line" ? 1 : 0; 
	}
	sort(r.begin(), r.end(), cmp);
	string nowName = "";
	double totalFee;
	int pretype, pretime, cnt=-1;
	for(int i=0; i<n; i++){
		if(r[i].name!=nowName){
			nowName = r[i].name;
			totalFee = 0.0;
			plist.push_back(person());
			cnt++;
			plist[cnt].name = nowName;
			if(r[i].type == 1){
				pretype = 1;
				pretime = r[i].time;
			}else pretype = 0;
		}else if(r[i].type == 1){
			pretype = 1;
			pretime = r[i].time;
		}else if(r[i].type == 0){
			if(pretype == 1){
				int sd = pretime/1440, ed = r[i].time/1440, s = pretime % 1440, e = r[i].time % 1440, cent = 0;
				int a = s/60, b = sd;
				while(a!=e/60 || b!=ed){//要注意计算跨天记录 
					cent += ((a+1)*60-s)*rate[a];
					s = (a+1)%24*60;
					a++;
					if(a == 24){
						a = 0;
						b++;
					}
				}
				cent += (e-s)*rate[e/60];
				double dollar = cent / 100.0;
				totalFee += dollar;
				plist[cnt].bill.push_back(charge(pretime/1440, pretime % 1440/60, pretime % 1440%60, ed, e/60, e%60, r[i].time-pretime, dollar));
				plist[cnt].totalfee += dollar;
			}
			pretype = 0;
		}
	}
	cout<<fixed<<setprecision(2)<<setfill('0');
	for(int i=0; i<plist.size(); i++){
		if(plist[i].totalfee == 0) continue;
		cout<<plist[i].name<<' '<<setw(2)<<month<<endl;
		for(int j=0; j<plist[i].bill.size(); j++){
			cout<<setw(2)<<plist[i].bill[j].sd<<':'<<setw(2)<<plist[i].bill[j].sh<<':'<<setw(2)<<plist[i].bill[j].sm<<' ';
			cout<<setw(2)<<plist[i].bill[j].ed<<':'<<setw(2)<<plist[i].bill[j].eh<<':'<<setw(2)<<plist[i].bill[j].em<<' ';
			cout<<plist[i].bill[j].minute<<" $"<<plist[i].bill[j].fee<<endl;
		}
		cout<<"Total amount: $"<<plist[i].totalfee<<endl;
	}
	return 0;
}

/*这道题当一个人的账单金额为0时不输出这个人，故不能采用边计算边输出的方式 
#include <bits/stdc++.h>
using namespace std;
int rate[24], n, month;
struct record{
	string name;
	int time, type;//online为1、off-line为0 
};
bool cmp(const record &a, const record &b){
	return a.name!=b.name?a.name<b.name:a.time<b.time;
}
int main(){
	ios::sync_with_stdio(false);
	for(int i=0; i<24; i++) cin>>rate[i];
	cin>>n;
	vector<record> r(n);
	for(int i=0; i<n; i++){
		string type;
		char t;
		int dd, hh, mm;
		cin>>r[i].name>>month>>t>>dd>>t>>hh>>t>>mm>>type;
		r[i].time = dd*1440 + hh*60 + mm;
		r[i].type = type=="on-line" ? 1 : 0; 
	}
	sort(r.begin(), r.end(), cmp);
	cout<<fixed<<setprecision(2)<<setfill('0');
	string nowName = "";
	double totalFee;
	int pretype, pretime;
	for(int i=0; i<=n; i++){
		if(i==n || r[i].name!=nowName){
			if(i != 0) cout<<"Total amount: $"<<totalFee<<endl;
			if(i == n) break;//注意输出最后一个人 
			nowName = r[i].name;
			totalFee = 0.0;
			cout<<nowName<<' '<<setw(2)<<month<<endl;
			if(r[i].type == 1){
				pretype = 1;
				pretime = r[i].time;
			}else pretype = 0;
		}else if(r[i].type == 1){
			pretype = 1;
			pretime = r[i].time;
		}else if(r[i].type == 0){
			if(pretype == 1){
				int sd = pretime/1440, ed = r[i].time/1440, s = pretime % 1440, e = r[i].time % 1440, cent = 0;
				cout<<setw(2)<<sd<<':'<<setw(2)<<s/60<<':'<<setw(2)<<s%60<<' ';
				cout<<setw(2)<<ed<<':'<<setw(2)<<e/60<<':'<<setw(2)<<e%60<<' ';
				cout<<r[i].time - pretime<<" $";
				int i = s/60, j = sd;
				while(i!=e/60 || j!=ed){//要注意计算跨天记录 
					cent += ((i+1)*60-s)*rate[i];
					s = (i+1)%24*60;
					i++;
					if(i == 24){
						i = 0;
						j++;
					}
				}
				cent += (e-s)*rate[e/60];
				double dollar = cent / 100.0;
				totalFee += dollar;
				cout<<dollar<<endl;
			}
			pretype = 0;
		}
	}
	return 0;
}
*/
