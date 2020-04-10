#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <map>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int max_length_substring(string s) {
	map<char, int> mp;
	int max=0;
	for(int i=0;i<s.length();i++){
		mp.clear();
		int len=0;
		for(int j=i;j<s.length()&&mp[s[j]]==0;j++){
			mp[s[j]]=1;
			len++;
		}
		if(len>max){
			max=len;
		}
	}
	return max;
}
/******************************结束写代码******************************/


int main() {
    int res;

    string _s;
    getline(cin, _s);
    
    res = max_length_substring(_s);
    cout << res << endl;
    
    return 0;

}

