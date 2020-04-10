#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;//�������
int prime[maxn], pNum = 0;//���������������
bool p[maxn] = {false};//p[1] == true��ʾi������
bool isPrime(int n){
	if(n < 2) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i=2; i<=sqr; i++){
		if(n % i == 0) return false;
	}
	return true;
}
void findPrime(){
	for(int i=0; i<maxn; i++){
		if(isPrime(i)){
			prime[pNum++] = i;
			p[i] = true;
		}
	}
} 

struct factor{
	int x, cnt;
}fac[10];//��һ��int�͵�������˵����10�͹���

int main(){
	findPrime();
	int n, num=0;
	cin>>n; 
	if(n < 2){
		cout<<"�޷��ֽ������ӣ�";
		return 0; 
	}
	int sqr = (int)sqrt(1.0 * n);
	for(int i=0; prime[i]<=sqr; i++){
		if(n % prime[i] == 0){
			fac[num].x = prime[i];
			fac[num].cnt = 0;
			while(n % prime[i] == 0){
				fac[num].cnt++;
				n /= prime[i];
			}
			num++;
		}
		if(n == 1) break;//��ʱ�˳�ѭ������ʡ��ʱ�� 
	}
	if(n != 1){//���n�޷�������n���ڵ������ӳ��� 
		fac[num].x = n;//��ôһ�����ҽ���һ�����ڸ���n�������� 
		fac[num++].cnt = 1;
	}
	for(int i=0; i<num; i++){
		while(fac[i].cnt--){
			cout<<fac[i].x<<' ';
		}
	}
	return 0; 
}
 
