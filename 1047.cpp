//�������cout�ᵼ�����һ�����Ե㳬ʱ���ü��ٺ���Ҳû��
//��ÿ���γ̵���������ʱ��Ҫֱ�������ַ�����Ҫ�����ַ����ı�ŴӶ����ٿ��� 
#include <bits/stdc++.h>
using namespace std;
char namelist[40010][5];
vector<int> courselist[2510];
int n, k;
bool cmp(int a, int b){
	return strcmp(namelist[a], namelist[b]) < 0;
}
int main(){
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++){
		int c, cnum;
		scanf("%s %d", namelist[i], &c);
		for(int j=0; j<c; j++){
			scanf("%d", &cnum);
			courselist[cnum].push_back(i);
		}
	}
	for(int i=1; i<=k; i++){
		printf("%d %d\n", i, courselist[i].size());
		sort(courselist[i].begin(), courselist[i].end(), cmp);
		for(auto &s : courselist[i]) printf("%s\n", namelist[s]);
	}
	return 0;
}

