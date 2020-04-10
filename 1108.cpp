//柳婼使用了sscanf和sprintf，比较简洁 
//下面是我写的字符串处理的思路，比较繁琐 
#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<double> v;
	while(n--){
		string in;
		cin>>in;
		bool legal = true, positive = true;
		double number = 0;
		int decimal = 0;
		for(int i=0; i<in.size(); i++){
			if(decimal >= 4){
				legal = false;
				break;
			}else if(isdigit(in[i])){
				number *= 10;
				number += in[i] - '0';
				if(decimal > 0) decimal++;
			}else if(in[i]=='-' && i==0){
				positive = false;
			}else if(in[i] == '.'){
				if(decimal > 0){
					legal = false;
					break;
				}else{
					decimal++;
				}
			}else{
				legal = false;
				break;
			}
		}
		if(decimal >= 4) legal = false;
		else if(decimal > 0) number /= pow(10, decimal-1);
		if(number > 1000) legal = false;
		if(positive == false) number = -number;
		if(legal){
			v.push_back(number);
		}else{
			cout<<"ERROR: "<<in<<" is not a legal number\n";
		}
	} 
	if(v.size() == 0){
		cout<<"The average of 0 numbers is Undefined";
	}else if(v.size() == 1){
		cout<<"The average of 1 number is "<<fixed<<setprecision(2)<<v[0];
	}else{
		/*double sum = 0;
		for(double it : v){
			sum += it;
		}*/
		double sum = accumulate(v.begin(), v.end(), 0.0);//第三个形参类型和返回值类型相同 
		sum /= v.size();
		cout<<"The average of "<<v.size()<<" numbers is "<<fixed<<setprecision(2)<<sum;
	}
	return 0;
}

