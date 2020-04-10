#include <bits/stdc++.h>
using namespace std;
const int opentime = 8 * 3600;
const int closetime = 21 * 3600;
int n, k, m;
struct player{
	int artime, pltime, vip;
	player(int a, int p, int v){
		artime = a;
		pltime = p;
		vip = v;
	}
};
struct table{
	int frtime = opentime, cnt = 0, vip = 0;
}tlist[101];
bool cmp1(const player &a, const player &b){
	return a.artime < b.artime;
}
int main(){
	list<player> plist;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int a, b, c, d, e, artime;
		scanf("%d:%d:%d %d %d", &a, &b, &c, &d, &e);
		artime = a * 3600 + b * 60 + c;
		if(artime < closetime) plist.push_back(player(artime, d, e));//���Ե�3���˿͵���ʱ��С�ڹر�ʱ��Ĳ��ܽӴ���Ӧ���йر�ʱ����ǰ�Ŀ������˿��ڹر�ʱ���Ժ󵽴����� 
	}
	plist.sort(cmp1);
	scanf("%d %d", &k, &m);
	for(int i=0; i<m; i++){
		int a;
		scanf("%d", &a);
		tlist[a].vip = 1;
	}
	while(!plist.empty()){
		list<player>::iterator it = plist.begin();
		int mintable, mintime = closetime;
		for(int i=1; i<=k; i++){
			if(tlist[i].frtime <= it->artime){
				mintime = tlist[i].frtime;
				mintable = i;
				break;
			}else if(tlist[i].frtime < mintime){
				mintime = tlist[i].frtime;
				mintable = i;
			}
		}
		if(mintime >= closetime) break;//���Ե�0������Ҫ��>=��Ӧ���йر�ʱ����ǰ�������ŶӵĹ˿͵�������ÿ���ʱ���ڹر�ʱ���Ժ���ֹͣ��� 
		if(tlist[mintable].vip == 1){
			bool vflag = false;
			for(;it!=plist.end() && it->artime<=mintime; it++){//���Ե�6������û��дit!=plist.end()�ǳ�ʱ�ĸ�Դ 
				if(it->vip == 1){
					vflag = true;
					break;
				} 
			}
			if(vflag == false) it = plist.begin(); 
		}else if(it->vip == 1){//���Ե�5��7��������׹˿���vip��������ڱ����С��vip�� 
			for(int i=1; i<=k; i++){
				if(tlist[i].vip==1 && tlist[i].frtime<=it->artime){
					mintime = tlist[i].frtime;
					mintable = i;
					break;
				}
			}
		}
		int setime = max(mintime, it->artime);
		printf("%02d:%02d:%02d ", it->artime/3600, it->artime%3600/60, it->artime%3600%60);
		printf("%02d:%02d:%02d ", setime/3600, setime%3600/60, setime%3600%60);
		printf("%d\n", (int)round((setime-it->artime)/60.0));//���Ե�8���������������������ȡ�� 
		tlist[mintable].frtime = setime + min(it->pltime, 120) * 60;//���Ե�4����������120���ӣ�����120���ӵ�Ҫѹ����120���� 
		tlist[mintable].cnt++;
		plist.erase(it);
	}
	for(int i=1; i<=k; i++){
		if(i != 1) printf(" ");
		printf("%d", tlist[i].cnt);
	}
	return 0;
}

