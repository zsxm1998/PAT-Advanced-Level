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
		bool setling = false;//�������Ϊtrue�����ling
		for(int i=2; i>=0; i--) { //�ֱ���λ�ڡ��򡢸��ڵ���λ��
			int base = pow(10000, i);//��λ�ڡ��򡢸�
			int num = n / base;//�����ڡ��򡢸�
			for(int j=3; j>=0; j--) { //�ֱ���λǧ���١�ʮ����
				int sbase = pow(10, j);//��λǧ���١�ʮ����
				int d = num / sbase;//����ǧ���١�ʮ���� ��Ҳ����������
				if(d) { //���������ֲ���0
					if(setling == true) { //���ǰ��������0����Ҫ���ling
						out += digit[0];
						setling = false;
					}
					out += digit[d] + unit[j];//������ּ���λ
				} else if(out.size()>3 && j>0) setling = true;//������������0�ҷ�����һλ����0ǰ��Ҫ��ling������ 
				num %= sbase;
			}
			if(n / base != 0) {//����ô�λ�ϲ�Ϊ0 
				out += unit[i+4];
				setling = false;
			} else {//����ô�λ��Ϊ0 
				if(out.size() > 3) setling = true;
				if(i==0 &&out.size()<=3) out = digit[0];//���⴦������Ϊ0��-0
			}
			n %= base;
		}
		cout<<out.substr(1)<<endl;
	}
	return 0;
}
/*��һ��ͨ���İ汾, ��Ȼͨ�������в��Ե㵫ʵ��Ӧ��������bug
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
	bool setling = false;//�������Ϊtrue�����ling
	for(int i=2; i>=0; i--){//�ֱ���λ�ڡ��򡢸��ڵ���λ��
		int base = pow(10000, i);//��λ�ڡ��򡢸�
		int num = n / base;//�����ڡ��򡢸�
		for(int j=3; j>=0; j--){//�ֱ���λǧ���١�ʮ����
			int sbase = pow(10, j);//��λǧ���١�ʮ����
			int d = num / sbase;//����ǧ���١�ʮ���� ��Ҳ����������
			if(d){//���������ֲ���0
				if(setling == true){//���ǰ��������0����Ҫ���ling
					out += digit[0];
					setling = false;
				}
				out += digit[d] + unit[j];//������ּ���λ
			}else{//������������0
				if(out.size() > 3) setling = true;
			}
			num %= sbase;
		}
		if(n / base != 0){//����ô�λ�ϲ�Ϊ0 
			out += unit[i+4];
		}else{//����ô�λ��Ϊ0 
			if(out.size() > 3) setling = true;
			if(i == 0 &&out.size()<=3) out = digit[0];//���⴦������Ϊ0��-0
		}
		n %= base;
	}
	cout<<out.substr(1);
	return 0;
}
*/
