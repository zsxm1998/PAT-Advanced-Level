#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int MAXN = 100010;
int st[MAXN], c[MAXN] = {0}, cnt = 0;
int getsum(int x){
	int sum = 0;
	for(int i=x; i>0; i-=lowbit(i)){
		sum += c[i];
	}
	return sum;
}
void update(int x, int v){
	for(int i=x; i<MAXN; i+=lowbit(i)){
		c[i] += v;
	}
}
int main(){
	ios::sync_with_stdio(false);
	bool popflag = false;
	int n;
	cin>>n;
	string command;
	while(n--){
		cin>>command;
		if(command == "Push"){
			int key;
			cin>>key;
			st[cnt++] = key;
			update(key, 1);
		}else if(command == "Pop"){
			if(cnt == 0) cout<<"Invalid\n";
			else{
				cout<<st[--cnt]<<endl;
				update(st[cnt], -1);
			}
		}else if(command == "PeekMedian"){
			if(cnt == 0) cout<<"Invalid\n";
			else{
				int left = 1, right = MAXN, mid, k = (cnt+1)/2;
				while(left < right){//�ö��ַ����� 
					mid = (left+right) / 2;
					if(getsum(mid) >= k) right = mid;
					else left = mid + 1;
				}
				cout<<left<<endl;
			}
		}
	}
	return 0;
}
/*����ʱ���м䣬��ȡ��ʱʱ�临�Ӷ�ΪO(1) 
#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int MAXN = 100010;
int st[MAXN], c[MAXN] = {0}, have[MAXN] = {0}, mid[MAXN] = {0}, cnt = 0;
int getsum(int x){
	int sum = 0;
	for(int i=x; i>0; i-=lowbit(i)){
		sum += c[i];
	}
	return sum;
}
void update(int x, int v){
	have[x] += v;
	for(int i=x; i<=MAXN; i+=lowbit(i)){
		c[i] += v;
	}
}
int main(){
	//if(freopen("input.txt", "r", stdin)==NULL) return 531529412;
	ios::sync_with_stdio(false);
	bool popflag = false;
	int n;
	cin>>n;
	string command;
	while(n--){
		cin>>command;
		if(command == "Push"){
			int key;
			cin>>key;
			st[cnt++] = key;
			update(key, 1);
			if(cnt == 1) mid[cnt] = key;
			else if(cnt%2==1 && key<=mid[cnt-1] || cnt%2==0 && key>=mid[cnt-1]) mid[cnt] = mid[cnt-1];
			else if(key>mid[cnt-1]){
				int left = mid[cnt-1], right = MAXN, m, k = (cnt+1)/2;//����left���ܵ���mid[cnt-1]+1��ԭ���ǿ����ڲ���key֮ǰջ���ж��mid[cnt-1]������key֮����λ������mid[cnt-1]���ʲ��ҷ�ΧҪ����mid[cnt-1] 
				while(left < right){
					m = (left+right) / 2;
					if(getsum(m) >= k) right = m;
					else left = m + 1;
				}
				mid[cnt] = left;
			}else{
				int left = 1, right = mid[cnt-1], m, k = (cnt+1)/2;//����right���ܵ���mid[cnt-1]-1��ԭ���ǿ����ڲ���key֮ǰջ���ж��mid[cnt-1]������key֮����λ������mid[cnt-1]���ʲ��ҷ�ΧҪ����mid[cnt-1] 
				while(left < right){
					m = (left+right) / 2;
					if(getsum(m) >= k) right = m;
					else left = m + 1;
				}
				mid[cnt] = left;
			}
		}else if(command == "Pop"){
			if(cnt == 0) cout<<"Invalid\n";
			else{
				cout<<st[--cnt]<<endl;
				update(st[cnt], -1);
			}
		}else if(command == "PeekMedian"){
			if(cnt == 0) cout<<"Invalid\n";
			else{
				cout<<mid[cnt]<<endl;
			}
		}
	}
	return 0;
}
*/
