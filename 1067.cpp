#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
vector<int> seq, pos;//seqΪ���У�pos[i]Ϊi��seq�е�λ�� 
void Swap(int x){
	swap(seq[pos[0]], seq[pos[x]]);//��seq�н���0��x 
	swap(pos[0], pos[x]);//����0��x��λ�� 
	cnt++;//����Swap������1 
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	seq.resize(n);
	pos.resize(n);
	for(int i=0; i<n; i++){
		cin>>seq[i];
		pos[seq[i]] = i;
	} 
	int t=0;//����t����1Ҳ���ԣ���Ϊ��ʼ�õ�tʱpos[0]һ������0����0һ���ᱻ���� 
	do{//λ����ȷ����һ�������ٱ���������ΪSwap��������0��λ�ò���ȷ���� 
		while(pos[0] != 0) Swap(pos[0]);//��0��λ�ò���0ʱ����0��0��λ�ö�Ӧ����������һ������λ 
		//t = 0;//ע�͵���仰���Ż���ʱ�Ĺؼ���֮ǰ������t�����ټ���ˣ�λ�ÿ϶���ȷ����Ϊλ����ȷ�������ᱻ������ע�͵���仰���Խ�ʱ�临�ӶȽ��͵����� 
		while(t<n && pos[t]==t) t++;//����pos������seq���棬����һ�е�����ѡ��������϶���ȷ�����ﲻ�õ���t���´�ѭ����û�й�λ����Ϊ�´μ�⻹�Ǵ�t��ʼ����tû�й�λ�򻹿��Լ�����0�Ƴ��� 
		if(t != n) Swap(t);//�����ұߵ�t������seq[t]��pos[t]���� 
	}while(t < n);
	cout<<cnt;
	return 0;
}

