#include <bits/stdc++.h>
using namespace std;
double cmax, d, davg;
int n;
struct station{
	double price, dis;
	station(){}
	station(double pp, double dd){
		price = pp;
		dis = dd;
	}
	friend bool operator<(const station &a, const station &b){
		return a.dis < b.dis;
	}
}; 
int main(){
	ios::sync_with_stdio(false);
	cin>>cmax>>d>>davg>>n;
	cout<<fixed<<setprecision(2);
	vector<station> sta(n);
	for(int i=0; i<n; i++) cin>>sta[i].price>>sta[i].dis;
	sort(sta.begin(), sta.end());
	sta.push_back(station(0.0, d));
	if(sta[0].dis != 0.0){
		cout<<"The maximum travel distance = 0.00";
		return 0;
	}
	int pos = 0;
	double maxl = cmax * davg, c = 0.0, tprice = 0.0;
	while(pos < n){
		int minpos = pos+1, cnt = 0;
		double minpri = sta[minpos].price;
		for(int i=pos+1; i<=n && sta[i].dis<=sta[pos].dis+maxl; i++){//这里后面的距离判断要用<=否则会出错 
			if(sta[i].price < sta[pos].price){//找的一个比当前价格低的就应该立即转移，而不是直接转移到范围内最低的那个 
				tprice += ((sta[i].dis-sta[pos].dis)/davg-c) * sta[pos].price;
				c = 0.0;
				pos = i;
				cnt = -1;
				break;
			}else if(sta[i].price < minpri){
				minpri = sta[i].price;
				minpos = i;
			}
			cnt++;
		}
		if(cnt == 0){
			cout<<"The maximum travel distance = "<<sta[pos].dis+maxl;
			return 0;
		}else if(cnt == -1) continue;
		else{
			tprice += (cmax-c) * sta[pos].price;
			c = cmax - (sta[minpos].dis-sta[pos].dis) / davg;
			pos = minpos;
		}
	}
	cout<<tprice;
	return 0;
}

