#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <map>

using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^ 
******************************��ʼд����******************************/
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
/******************************����д����******************************/


int main() {
    int res;

    string _s;
    getline(cin, _s);
    
    res = max_length_substring(_s);
    cout << res << endl;
    
    return 0;

}

