#include <bits/stdc++.h>
using namespace std;
string digit[10] = {" ling", " yi", " er", " san", " si", " wu", " liu", " qi", " ba", " jiu"};
string unit[7] = {"", " Shi", " Bai", " Qian", "", " Wan", " Yi"};
int main() {
	int n;
	while(cin>>n) {
		string out;
		if(n < 0) {
			out += " Fu";
			n = -n;
		}
		bool setling = false;//遇到这个为true就添加ling
		for(int i=2; i>=0; i--) { //分别处理单位亿、万、个内的四位数
			int base = pow(10000, i);//单位亿、万、个
			int num = n / base;//几个亿、万、个
			for(int j=3; j>=0; j--) { //分别处理单位千、百、十、个
				int sbase = pow(10, j);//单位千、百、十、个
				int d = num / sbase;//几个千、百、十、个 ，也即单个数字
				if(d) { //如果这个数字不是0
					if(setling == true) { //如果前面有数字0且需要输出ling
						out += digit[0];
						setling = false;
					}
					out += digit[d] + unit[j];//输出数字及单位
				} else if(out.size()>3 && j>0) setling = true;//如果这个数字是0且符合下一位不是0前面要填ling的条件 
				num %= sbase;
			}
			if(n / base != 0) {//如果该大单位上不为0 
				out += unit[i+4];
				setling = false;
			} else {//如果该大单位上为0 
				if(out.size() > 3) setling = true;
				if(i==0 &&out.size()<=3) out = digit[0];//特殊处理输入为0和-0
			}
			n %= base;
		}
		cout<<out.substr(1)<<endl;
	}
	return 0;
}
/*第一次通过的版本, 虽然通过了所有测试点但实际应用起来有bug
#include <bits/stdc++.h>
using namespace std;
string digit[10] = {" ling", " yi", " er", " san", " si", " wu", " liu", " qi", " ba", " jiu"};
string unit[7] = {"", " Shi", " Bai", " Qian", "", " Wan", " Yi"};
int main(){
	int n;
	string out;
	cin>>n;
	if(n < 0){
		out += " Fu";
		n = -n;
	}
	bool setling = false;//遇到这个为true就添加ling
	for(int i=2; i>=0; i--){//分别处理单位亿、万、个内的四位数
		int base = pow(10000, i);//单位亿、万、个
		int num = n / base;//几个亿、万、个
		for(int j=3; j>=0; j--){//分别处理单位千、百、十、个
			int sbase = pow(10, j);//单位千、百、十、个
			int d = num / sbase;//几个千、百、十、个 ，也即单个数字
			if(d){//如果这个数字不是0
				if(setling == true){//如果前面有数字0且需要输出ling
					out += digit[0];
					setling = false;
				}
				out += digit[d] + unit[j];//输出数字及单位
			}else{//如果这个数字是0
				if(out.size() > 3) setling = true;
			}
			num %= sbase;
		}
		if(n / base != 0){//如果该大单位上不为0 
			out += unit[i+4];
		}else{//如果该大单位上为0 
			if(out.size() > 3) setling = true;
			if(i == 0 &&out.size()<=3) out = digit[0];//特殊处理输入为0和-0
		}
		n %= base;
	}
	cout<<out.substr(1);
	return 0;
}
*/
