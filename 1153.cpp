#include <bits/stdc++.h>
using namespace std;
//排序要使用引用传参：bool cmp(const card &c1, const card &c2)

struct card{
	char level;
	int site, date, num, score;
	card(char input[], char sc[]){
		level = input[0];
		stringstream ss;
		ss<<(input+1);
		long long tmp;
		ss>>tmp;
		//tmp = atoll(input+1);
		site = tmp / 1000000000;
		tmp = tmp % 1000000000;
		date = tmp / 1000;
		num = tmp % 1000;
		score = atoi(sc);	
	}
};
vector<card> line, lineT, lineA, lineB;

bool cmp(const card &c1, const card &c2){
	if(c1.level != c2.level){
		return c1.level < c2.level;
	}else if(c1.score != c2.score){
		return c1.score > c2.score;
	}else if(c1.site != c2.site){
		return c1.site < c2.site;
	}else if(c1.date != c2.date){
		return c1.date < c2.date;
	}else{
		return c1.num < c2.num;
	}
}

struct Site{
	int snum, tnum;
	Site(int s, int t):snum(s), tnum(t){}
};

bool cmp2(const Site &s1, const Site &s2){
	if(s1.tnum != s2.tnum){
		return s1.tnum > s2.tnum;
	}else{
		return s1.snum < s2.snum;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		char input[14], score[4];
		cin>>input>>score;
		line.push_back(card(input, score));
	}
	sort(line.begin(),line.end(), cmp);
	for(auto t: line){
		if(t.level == 'A'){
			lineA.push_back(t);
		}else if(t.level == 'B'){
			lineB.push_back(t);
		}else{
			lineT.push_back(t);
		}
	}
	for(int i=1; i<=m; i++){
		int type, count=0;
		char term[7];
		cin>>type>>term;
		cout<<"Case "<<i<<": "<<type<<' '<<term<<endl;
		if(type == 1){
			if(term[0] == 'T'){
				for(auto t:lineT){
					cout<<setfill('0')<<t.level<<t.site<<setw(6)<<t.date<<setw(3)<<t.num<<' '<<t.score<<endl;
					count++;
				}
			}
			else if(term[0] == 'A'){
				for(auto t:lineA){
					cout<<setfill('0')<<t.level<<t.site<<setw(6)<<t.date<<setw(3)<<t.num<<' '<<t.score<<endl;
					count++;
				}
			}
			else if(term[0] == 'B'){
				for(auto t:lineB){
					cout<<setfill('0')<<t.level<<t.site<<setw(6)<<t.date<<setw(3)<<t.num<<' '<<t.score<<endl;
					count++;
				}
			}
			if(!count){
				cout<<"NA\n";
			}
		}else if(type == 2){
			int site = atoi(term), sum=0;
			for(auto t:line){
				if(t.site == site){
					count++;
					sum += t.score;
				}
			}
			if(count){
				cout<<count<<' '<<sum<<endl;
			}else{
				cout<<"NA\n";
			}
		}else if(type == 3){
			int mp[1000] = {0};
			vector<Site> siteLine;
			int date = atoi(term);
			for(auto t:line){
				if(t.date == date){
					count++;
					mp[t.site]++;
				}
			}
			if(count){
				for(int j=0; j<1000;j++){
					if(mp[j]){
						siteLine.push_back(Site(j, mp[j]));
					}
				}
				sort(siteLine.begin(), siteLine.end(), cmp2);
				for(auto t:siteLine){
					cout<<t.snum<<' '<<t.tnum<<endl;
				}
			}else{
				cout<<"NA\n";
			}
		}
	}
	return 0;
} 
/*附上柳婼的代码供学习
#include <iostream>
#include <vector>
#include <unordered_map>  //用unordered_map加快速度 
#include <algorithm>
using namespace std ;
struct  node {  //查询1和查询3的输出数据格式相同 
    string  t;
    int  value;
};
bool cmp (const node &a, const node &b) {  //查询1和查询3的输出数据排序规则相同 
    return  a.value != b.value ? a.value > b.value :  a.t < b.t;  //冒号表达式书写cmp函数值得学习 
}
int  main() {  //本程序并未调用sync_with_stdio()却仍速度可观，经过测试万级别数据相差10ms左右 
    int  n, k, num ;
    string  s;
    cin  >> n >> k;
    vector <node> v(n);  //直接调用vector的构造函数设置长度 
    for  (int  i = 0; i < n; i++)
         cin  >> v[i].t >> v[i].value;   //cin可直接输入string 
    for  (int  i = 1; i <= k; i++) {
         cin  >> num  >> s;
         printf ("Case %d: %d %s\n" , i, num , s.c_str()); //string.c_str()返回string的字符数组形式 
         vector <node> ans ;
         int  cnt  = 0, sum  = 0;
         if (num  == 1) {
            for  (int  j = 0; j < n; j++)
                 if (v[j].t[0] == s[0])  ans .push_back(v[j]);
        } else if (num  == 2) {
            for  (int  j = 0; j < n; j++) {
                 if (v[j].t.substr (1, 3) == s) {  //string.substr()求字串； string可以直接比大小，字典序 
                    cnt ++;
                    sum  += v[j].value;
                }
            }
            if (cnt  != 0) printf ("%d %d\n", cnt , sum );
        } else if (num  == 3) {
            unordered_map <string , int > m;
            for  (int  j = 0; j < n; j++)
                 if (v[j].t.substr (4, 6) == s) m[v[j].t.substr (1, 3)]++;
            for  (auto it :  m) ans .push_back({it.first, it.second });  //这种给vector添加元素的方式值得学习 
        }
         sort(ans .begin(), ans .end (), cmp );
         for  (int  j = 0; j < ans .size(); j++)
            printf ("%s %d\n", ans [j].t.c_str(), ans [j].value);
         if (((num  == 1 || num  == 3) && ans .size()  == 0) || (num  == 2 && cnt  == 0))  printf ("NA\n" );
    }
    return  0;
} 
*/
