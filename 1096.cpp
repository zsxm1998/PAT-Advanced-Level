//��һ��ͨ���Ĵ��룬��nΪ������ֱ�����n�����������2��sqrt(n)+1������5ms 
#include <bits/stdc++.h>
using namespace std;
int sqr, n;
bool isprime(){
	sqr = (int)sqrt(n);
	for(int i=2; i<=sqr; i++){
		if(n % i == 0) return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	vector<int> path, temPath;
	cin>>n;
    if(isprime()){
        cout<<"1\n"<<n;
        return 0;
    }
	for(int i=2; i<=sqr; i++){
		int remain = n;
		for(int j=i; j<=sqr+1; j++){//������Ҫ��sqr+1�����������ĩβ��sqrʱ���޷����� 
			if(remain % j == 0){
				temPath.push_back(j);
				remain /= j;
			}else{
				if(temPath.size() > path.size()) path = temPath;
				temPath.clear();
				break;
			}
		}
	}
	cout<<path.size()<<endl;
	for(int i=0; i<path.size(); i++){
		if(i > 0)cout<<'*';
		cout<<path[i];
	}
	return 0;
}

/*˫ָ�뷨�����һ�����Ե�ᳬʱ���޷��Ż�����Ϊ����������������� 
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n, i = 1, j = 2, left = 1, right = 0, product = 1;
	cin>>n;
	//int sqr = (int)sqrt(n);
	while(i <= n){
		do{
			i++;
			product *= i;
		}while(n % product == 0);
		if(i-j > right-left){
			left = j;
			right = i;
		}
		do{
			product /= j;
			j++;
		}while(n % product != 0);
	}
	cout<<right-left;
	for(int i=left; i<right; i++){
		cout<<(i==left?'\n':'*')<<i;
	}
	return 0;
}
*/
/*��һ��ͨ���Ĵ��룬��nΪ������ֱ�����n�����������2��sqrt(n)+1������5ms 
#include <bits/stdc++.h>
using namespace std;
int sqr, n;
bool isprime(){
	sqr = (int)sqrt(n);
	for(int i=2; i<=sqr; i++){
		if(n % i == 0) return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	vector<int> path, temPath;
	cin>>n;
    if(isprime()){
        cout<<"1\n"<<n;
        return 0;
    }
	for(int i=2; i<=sqr; i++){
		int remain = n;
		for(int j=i; j<=sqr+1; j++){//������Ҫ��sqr+1�����������ĩβ��sqrʱ���޷����� 
			if(remain % j == 0){
				temPath.push_back(j);
				remain /= j;
			}else{
				if(temPath.size() > path.size()) path = temPath;
				temPath.clear();
				break;
			}
		}
	}
	cout<<path.size()<<endl;
	for(int i=0; i<path.size(); i++){
		if(i > 0)cout<<'*';
		cout<<path[i];
	}
	return 0;
}
*/
