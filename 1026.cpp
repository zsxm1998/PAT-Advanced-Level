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
		if(artime < closetime) plist.push_back(player(artime, d, e));//测试点3：顾客到达时间小于关闭时间的才能接待，应对有关闭时间以前的空桌但顾客在关闭时间以后到达的情况 
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
		if(mintime >= closetime) break;//测试点0：这里要用>=，应对有关闭时间以前来的在排队的顾客的情况，让空桌时间在关闭时间以后则停止输出 
		if(tlist[mintable].vip == 1){
			bool vflag = false;
			for(;it!=plist.end() && it->artime<=mintime; it++){//测试点6：这里没有写it!=plist.end()是超时的根源 
				if(it->vip == 1){
					vflag = true;
					break;
				} 
			}
			if(vflag == false) it = plist.begin(); 
		}else if(it->vip == 1){//测试点5、7：如果队首顾客是vip则将其分配在编号最小的vip桌 
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
		printf("%d\n", (int)round((setime-it->artime)/60.0));//测试点8：是四舍五入而不是向上取整 
		tlist[mintable].frtime = setime + min(it->pltime, 120) * 60;//测试点4：玩家最多玩120分钟，超过120分钟的要压缩到120分钟 
		tlist[mintable].cnt++;
		plist.erase(it);
	}
	for(int i=1; i<=k; i++){
		if(i != 1) printf(" ");
		printf("%d", tlist[i].cnt);
	}
	return 0;
}

