#include <bits/stdc++.h>
using namespace std;
string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"}; 
int main(){
	ios::sync_with_stdio(false);
	string a, b, c, d;
	cin>>a>>b>>c>>d;
	int i = 0, cnt = 0;
	while(i<a.size() && i<b.size()){
		if(a[i] == b[i]){
			if(cnt==0 && isupper(a[i]) && a[i]<='G'){//注意范围，否则会出错 
				cout<<week[a[i]-'A']<<' ';
				cnt++;
			}else if(cnt==1 && isdigit(a[i])){
				cout<<setfill('0')<<setw(2)<<(int)(a[i]-'0');
				cnt++;
			}else if(cnt==1 && isupper(a[i]) && a[i]<='N'){//注意范围，否则会出错 
				cout<<setfill('0')<<setw(2)<<(int)(a[i]-'A'+10);
				cnt++;
			}
		}else if(cnt == 2) break;
		i++;
	}
	i = 0;
	while(i<c.size() && i<d.size()){
		if(c[i] == d[i] && isalpha(c[i])){
			cout<<':'<<setw(2)<<i;
			break;
		} 
		i++;
	}
	return 0;
}

