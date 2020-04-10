#include<bits/stdc++.h>
using namespace std;
vector<int> pre, in, post;
bool uniqueFlag = true;

void getInFromPreAndPost(int prel, int prer, int postl, int postr){//ֱ��ͨ���������кͺ������д�ӡ�������� 
	if(prel == prer){
		in.push_back(pre[prel]);
		return;
	}
	int i=prel + 1;
	while(pre[i]!=post[postr-1]){//�������������ҵ��������ĸ��ڵ�λ�� 
		i++;
	}
	if(i-prel > 1){//��ǰ������������ 
		int numl = i-prel-1;
		getInFromPreAndPost(prel+1, prel+numl, postl, postl+numl-1);
		in.push_back(pre[prel]);
		getInFromPreAndPost(i, prer, postl+numl, postr-1);
	}else{//��ǰ��ֻ��һ���������޷�ȷ����������������������������Ϊ�����������д�ӡ 
		uniqueFlag = false;
		getInFromPreAndPost(i, prer, postl, postr-1);
		in.push_back(pre[prel]);
	}
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	pre.resize(n);
	post.resize(n);
	for(int i=0; i<n; i++){
		cin>>pre[i];
	}
	for(int i=0; i<n; i++){
		cin>>post[i];
	}
	getInFromPreAndPost(0, n-1, 0, n-1);
	cout<<(uniqueFlag?"Yes":"No")<<endl;//printf("%s\n", uniqueFlag?"Yes":"No");
	cout<<in[0];
	for(int i=1; i<n; i++){
		cout<<' '<<in[i];
	}
	cout<<endl;
	return 0;
}
