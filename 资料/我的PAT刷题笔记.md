# 我的PAT刷题笔记

0. 英语单词

```c++
/*
specification 规范
test case 测试用例
consecutive 连续的
transcendental number 超越数
positive integer 正整数
significant digit 有效数字
round 四舍五入
topological order 拓扑序列
permutation 序列、排列
quadratic probing 平方探测
palindrome 回文
parentheses 圆括号
infix expression 中缀表达式
syntax tree 语法树
Eulerian 欧拉的
prime number质数
recursive 递归的 recursion 递归
factorization 因式分解
arithmetic 算数
sum 和
difference 差
product 商
quotient 积
denominator 分母
numerator 分子
fraction 分数
quadratic probing 平方探测
lexicographically 字典序地
radix 进制，基数
acyclic 无环的
polynomial 多项式
coefficient 系数
*/
```

1. fill函数初始化二维数组

```c++
const int MAXV = 210;
const int INF = 0x3fffffff;
int G[MAXV][MAXV];
fill(G[0], G[0] + MAXV * MAXV, INF);
```

2. 将string全部转化为大写或小写，transform函数

```c++
#include <algorithm>
#include <cctype>
//一元操作
string st="aBc";
transform(st.begin(), st.end(), st.begin(), ::toupper);//转换为大写
transform(st.begin(), st.end(), st.begin(), ::tolower);//转换为小写
//二元操作
int add_op(int a, int b){
	return a+b;
}
vector<int> x(10), y(10);
for(int i=0; i<10; i++) x[i] = y[i] = i;
transform(x.begin(), x.end(), y.begin(), x.begin(), add_op);
for(int i=0; i<10; i++) cout<<x[i]<<' ';//0 2 4 6 8 10 12 14 16 18
```

3. 万能头文件

```c++
#include <bits/stdc++.h>
```

4. 加快c++输入输出流速度

```c++
ios::sync_with_stdio(false);//这条语句起主要作用
cin.tie(NULL);
```

5. 排序要使用引用传参加快速度

```c++
bool cmp(const node &n1, const node &n2){}
```

6. STL中除了vector和string之外的容器只支持 _it++_ 而不支持 _it+1_ 
7. 辗转相除法求最大公约数

```c++
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}//柳婼的
int gcd(int a, int b){
    return !(a%b) ? b : gcd(b, a%b);
}//我的，有问题，不能处理a和b都是0的情况
```

8. 宽度为4输出，前面补0

```c++
cout<<setfill('0')<<setw(4)<<rs.first<<' '<<setw(4)<<rs.second<<endl;
printf("%04d %04d\n", rs.first, rs.second);
```

9. 要输入一行数据的话

```c++
#include <string>
string s;
getline(cin, s);

#include <iostream>
char str[100];
cin.getline(str, 100);//一行字符串超长会错误
cin.get(str, 100);//只是读取指定长度字符串，一行长度超长不会错误
gets(str);
```

10. string转int、double

```c++
#include <string>
int stoi(string s, std::size_t* pos, int base);//输入字符串，第一个非数字字符的下标，进制
long long stoll(string s, std::size_t* pos, int base);
double stod(string s, std::size_t* pos, int base);

#include <cstdlib>
int atoi(const char *str);//转化字符数组的
long long atoll(const char * str);
double atof(const char * str);
```

11. int、double转string

```c++
#include <string>
string to_string(int value);
string to_string(long long value);
string to_string(double value);
```

12. stringstream用法

```c++
#include <sstream>
stringstream ss;
string str = 'abc';
ss<<str;
int i;
ss>>i;

istringstream iss(str);
iss>>i;
```

13. 循环判断输入数据是否结束

```c++
while(cin>>a>>b){}//应该用这个
while(!cin.eof()){cin>>a>>b;}//用这个会出错
while(scanf("%d %d",&a, &b) != EOF){}//C语言
```

14. string等的size()函数返回值是size_type类型，是一个unsigned类型， 若将其直接与一个大于它的整数相减则得不到正确的负数，需用(int)强制转换。

```c++
string in;
getline(cin, in);
while((int)in.size()-8 < 0){}
```

15. string拼接

```c++
string str1 = "abc", str2 = "def", str3;
str3 = str1 + str2;
str3 += str2;
str3 += "xyz";
str3 += string("xyz");
```

16. cin、cout其他进制输入输出

```c++
int n;
cin>>hex>>n;
cout<<dec<<n;
//oct:八进制
//dec:十进制
//hex:十六进制
//uppercase:十六进制格式字母变大写
//showpos:在正数前显示+号
//showbase:十六进制前显示0x，八进制前显示0
//boolalpha:逻辑值1和0用true和false输出
//left:输出内容靠左
//right:输出内容靠右
//scientific:科学记数法
//showpoint:即使小数后面都是0，也输出小数点。
#include <bitset>
const int num = 32;
int n = 100;
cout<<(bitset<num>)n;//将n以num位二进制输出
```

17. 迭代器遍历删除vector、list和map中的元素

```c++
//对于vector、list, erase会返回下一个iterator, 因此我们可以使用如下的方法:
int main()
{
    vector<int> a = {12, 23, 34, 45, 56, 67, 78, 89};
    auto iter = a.begin();
    while (iter != a.end()) {
        if (*iter > 30) {
            iter = a.erase(iter);//另iter等于erase函数返回值
        }
        else {
            ++iter;
        }
    }
    for (const auto &element : a) {
        cout<<element<<endl;
    }
}
//对于map, 删除iterator只会影响当前的iterator, 因此使用for循环就够了, 比如:
int main()
{
    map<int, int> a = {{1, 12}, {2, 23}, {3, 34}, {4, 45}, {5, 56}, {6, 67}};
    for (auto iter = a.begin(); iter != a.end(); ++iter) {
        if (iter->second > 30) {
            a.erase(iter);
        }
    } 
    for (const auto &element : a) {
        cout<<element.first<<" : "<<element.second<<endl;
    }
}
//但是更推荐的做法是在erase前让iterator指向下一个元素:
int main()
{
    map<int, int> a = {{1, 12}, {2, 23}, {3, 34}, {4, 45}, {5, 56}, {6, 67}};
    auto iter = a.begin();
    while (iter != a.end()) {
        if (iter->second > 30) {
            a.erase(iter++);
            //a.erase(iter);我自己测试好像这样写也可以
            //iter++;连上句
        }
        else {
            ++iter;
        }
    }
    for (const auto &element : a) {
        cout<<element.first<<" : "<<element.second<<endl;
    }
}
```

18. cmp函数的优化写法

```c++
struct Student{
	string id;
	int gp = -1, gm = -1, gf = -1, g = -1;
};
bool cmp(Student a, Student b){
	/*if(a.g != b.g){
		return a.g > b.g;
	}else{
		return a.id < b.id;
	}*///优化写法：
	return  a.g != b.g ? a.g > b.g : a.id < b.id;
}
```

19. 给vector添加元素时的优化写法

```c++
struct Student{
	string id;
	//int gp = -1, gm = -1, gf = -1, g = -1;//当这样写时优化写法会报错
    int gp, gm, gf, g;
};
map<string, Student> mp;
vector<Student> v;
for(auto i : mp){
		/*Student temp;
		temp.id = i.second.id;
		temp.gp = i.second.gp;
		temp.gm = i.second.gm;
		temp.gf = i.second.gf;
		temp.g = i.second.g;
		v.push_back(temp);*///优化写法 
		v.push_back(Student{i.second.id, i.second.gp, i.second.gm, i.second.gf, i.second.g});
}
```

20. 按一个BST的先序遍历序列进行create函数可以还原这个BST

21. 当想使用set的find函数查找set内的结构体，但苦于只知道结构体中的一个元素而不知道另一个而无法给find传参，可以通过开一个hash数组的方式把另一个元素存储起来，这样就可以构造find函数所需要的结构体参数了。
22. set内部排序规则更改

```c++
//结构体，重载的运算符函数内的符号和cmp规则相同，和priority_queue相反
struct item{
	int id, freq;
	friend bool operator<(const item &a, const item &b){
		return a.freq != b.freq ? a.freq > b.freq : a.id < b.id;
	}
};
set<item> st;//自动按设置的规则排序
//基本类型
set<int, less<int>> st;//升序排序
set<int, greater<int>> st;//降序排序
```

23. 重定向标准输入输出流到文件

```c++
//C式写法， 对cin、cout和scanf、printf等等都有效
ios::sync_with_stdio(false);//这两句话加与不加对cin和cout没有影响
cin.tie(NULL);//这两句话加与不加对cin和cout没有影响
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
string str;
while(cin>>str){
    cout<<str<<endl;
}
while(getline(cin, str)){
    cout<<str<<endl;
}
char st[1024];
while(cin.getline(st, 1024)){
    cout<<st<<endl;
}
while(scanf("%s", st) != EOF){
    printf("%s\n", st);
}
while(gets(st)){//gets函数不判断上限，所以必须保证字符串数组足够大
    printf("%s\n", st);
}
//C++式写法，这种写法只能重定向cin、cout，而scanf、printf、gets等不能重定向
ifstream fin("input.txt");
ofstream fout("output.txt");
streambuf* cinbackup = cin.rdbuf(fin.rdbuf());//若不需要还原到键盘则可不写前面的变量
streambuf* coutbackup = cout.rdbuf(fout.rdbuf());//若不需要还原到屏幕则可不写前面的变量
cin.rdbuf(cinbackup);//还原键盘输入
cout.rdbuf(coutbackup);//还原屏幕输出
```

24. stringstream清空

```c++
stringstream ss;
ss.clear();//清空流状态 
ss.str("");//清空流内容
```

25. string可以直接和字符串常量使用==进行判断；map以string作为值默认为空字符串""

```c++
cout<<(string("abc")=="aaa")<<(string("abc")=="abc")<<(""==string())<<endl;//输出011
string a=string("xyz"), b=string();
cout<<("xyz"==a)<<(b=="")<<endl;//输出11
map<string, string> mp;
cout<<(mp["uvw"]=="")<<(mp["uvw"]==string());//输出11
mp["uvw"] = "aaa";
cout<<(mp[string("uvw")]=="sss")<<(mp[string("uvw")]=="aaa");//输出01
```

26. vector基本类型sort函数

```c++
vector<int> v;
sort(v.begin(), v.end(), greater<int>());//从大到小排序
```

27. cout格式化输出

### 使用流操作算子

C++ 中常用的输出流操纵算子如下表所示，它们都是在头文件 iomanip 中定义的；要使用这些流操纵算子，必须包含该头文件。

> 注意：“流操纵算子”一栏中的星号`*`不是算子的一部分，星号表示在没有使用任何算子的情况下，就等效于使用了该算子。例如，在默认情况下，整数是用十进制形式输出的，等效于使用了 dec 算子。

| 流操纵算子          | 作  用                                                       |        |
| ------------------- | ------------------------------------------------------------ | ------ |
| *dec                | 以十进制形式输出整数                                         | 常用   |
| hex                 | 以十六进制形式输出整数                                       |        |
| oct                 | 以八进制形式输出整数                                         |        |
| fixed               | 以普通小数形式输出浮点数                                     |        |
| scientific          | 以科学计数法形式输出浮点数                                   |        |
| left                | 左对齐，即在宽度不足时将填充字符添加到右边                   |        |
| *right              | 右对齐，即在宽度不足时将填充字符添加到左边                   |        |
| setbase(b)          | 设置输出整数时的进制，b=8、10 或 16                          |        |
| setw(w)             | 指定输出宽度为 w 个字符，或输人字符串时读入 w 个字符         |        |
| setfill(c)          | 在指定输出宽度的情况下，输出的宽度不足时用字符 c 填充（默认情况是用空格填充） |        |
| setprecision(n)     | 设置输出浮点数的精度为 n。  在使用非 fixed 且非 scientific 方式输出的情况下，n 即为有效数字最多的位数，如果有效数字位数超过 n，则小数部分四舍五人，或自动变为科学计 数法输出并保留一共 n 位有效数字。  在使用 fixed 方式和 scientific 方式输出的情况下，n 是小数点后面应保留的位数。 |        |
| setiosflags(flag)   | 将某个输出格式标志置为 1                                     |        |
| resetiosflags(flag) | 将某个输出格式标志置为 0                                     |        |
| boolapha            | 把 true 和 false 输出为字符串                                | 不常用 |
| *noboolalpha        | 把 true 和 false 输出为 0、1                                 |        |
| showbase            | 输出表示数值的进制的前缀                                     |        |
| *noshowbase         | 不输出表示数值的进制.的前缀                                  |        |
| showpoint           | 总是输出小数点                                               |        |
| *noshowpoint        | 只有当小数部分存在时才显示小数点                             |        |
| showpos             | 在非负数值中显示 +                                           |        |
| *noshowpos          | 在非负数值中不显示 +                                         |        |
| *skipws             | 输入时跳过空白字符                                           |        |
| noskipws            | 输入时不跳过空白字符                                         |        |
| uppercase           | 十六进制数中使用 A~E。若输出前缀，则前缀输出 0X，科学计数法中输出 E |        |
| *nouppercase        | 十六进制数中使用 a~e。若输出前缀，则前缀输出 0x，科学计数法中输出 e。 |        |
| internal            | 数值的符号（正负号）在指定宽度内左对齐，数值右对 齐，中间由填充字符填充。 |        |

#### 流操作算子的使用方法

使用这些算子的方法是将算子用 << 和 cout 连用。例如：

```
cout << hex << 12 << "," << 24;
```

这条语句的作用是指定以十六进制形式输出后面两个数，因此输出结果是：
c, 18

#### setiosflags() 算子

setiosflags() 算子实际上是一个库函数，它以一些标志作为参数，这些标志可以是在 iostream 头文件中定义的以下几种取值，它们的含义和同名算子一样。

| 标 志           | 作 用                                                        |
| --------------- | ------------------------------------------------------------ |
| ios::left       | 输出数据在本域宽范围内向左对齐                               |
| ios::right      | 输出数据在本域宽范围内向右对齐                               |
| ios::internal   | 数值的符号位在域宽内左对齐，数值右对齐，中间由填充字符填充   |
| ios::dec        | 设置整数的基数为 10                                          |
| ios::oct        | 设置整数的基数为 8                                           |
| ios::hex        | 设置整数的基数为 16                                          |
| ios::showbase   | 强制输出整数的基数（八进制数以 0 开头，十六进制数以 0x 打头） |
| ios::showpoint  | 强制输出浮点数的小点和尾数 0                                 |
| ios::uppercase  | 在以科学记数法格式 E 和以十六进制输出字母时以大写表示        |
| ios::showpos    | 对正数显示“+”号                                              |
| ios::scientific | 浮点数以科学记数法格式输出                                   |
| ios::fixed      | 浮点数以定点格式（小数形式）输出                             |
| ios::unitbuf    | 每次输出之后刷新所有的流                                     |
| ios::stdio      | 每次输出之后清除 stdout, stderr                              |


这些标志实际上都是仅有某比特位为 1，而其他比特位都为 0 的整数。

多个标志可以用`|`运算符连接，表示同时设置。例如：

```
cout << setiosflags(ios::scientific|ios::showpos) << 12.34;
```

输出结果是：
+1.234000e+001

如果两个相互矛盾的标志同时被设置，如先设置 setiosflags(ios::fixed)，然后又设置 setiosflags(ios::scientific)，那么结果可能就是两个标志都不起作用。因此，在设置了某标志，又要设置其他与之矛盾的标志时，就应该用 resetiosflags 清除原先的标志。例如下面三条语句：

```
cout << setiosflags(ios::fixed) << 12.34 << endl;cout << resetiosflags(ios::fixed) << setiosflags(ios::scientific | ios::showpos) << 12.34 << endl;cout << resetiosflags(ios::showpos) << 12.34 << endl;  //清除要输出正号的标志
```

输出结果是：
12.340000
+1.234000e+001
1.234000e+001

#### 综合示例

关于流操纵算子的使用，来看下面的程序。

```c++
#include <iostream>
#include <iomanip>
using namespace std;
int main(){    
    int n = 141;    
    //1) 分别以十六进制、十进制、八进制先后输出 n    
    cout << "1)" << hex << n << " " << dec << n << " " << oct << n << endl;    
    double x = 1234567.89, y = 12.34567;    
    //2)保留5位有效数字    
    cout << "2)" << setprecision(5) << x << " " << y << " " << endl;    
    //3)保留小数点后面5位    
    cout << "3)" << fixed << setprecision(5) << x << " " << y << endl;    
    //4)科学计数法输出，且保留小数点后面5位    
    cout << "4)" << scientific << setprecision(5) << x << " " << y << endl;    
    //5)非负数显示正号，输出宽度为12字符，宽度不足则用 ! 填补    
    cout << "5)" << showpos << fixed << setw(12) << setfill('!') << 12.1 << endl;    
    //6)非负数不显示正号，输出宽度为12字符，宽度不足则右边用填充字符填充    
    cout << "6)" << noshowpos << setw(12) << left << 12.1 << endl;    
    //7)输出宽度为 12 字符，宽度不足则左边用填充字符填充    
    cout << "7)" << setw(12) << right << 12.1 << endl;    
    //8)宽度不足时，负号和数值分列左右，中间用填充字符填充    
    cout << "8)" << setw(12) << internal << -12.1 << endl;    
    cout << "9)" << 12.1 << endl;    
    return 0;
}
```

程序的输出结果是：
1)8d 141 215
2)1.2346e+06 12.346
3)1234567.89000 12.34567
4)1.23457e+06 1.23457e+01
5)!!!+12.10000
6)12.10000!!!!
7)!!!!12.10000
8)-!!!12.10000
9)12.10000

需要注意的是，setw() 算子所起的作用是一次性的，即只影响下一次输出。每次需要指定输出宽度时都要使用 setw()。因此可以看到，第 9) 行的输出因为没有使用 setw()，输出的宽度就不再是前面指定的 12 个字符。

在读入字符串时，setw() 还能影响 cin 的行为。例如下面的程序：

```c++
#include <iostream>
#include <iomanip>
using namespace std;
int main(){    
    string s1, s2;   
    cin >> setw(4) >> s1 >> setw(3) >> s2;   
    cout << s1 << "," << s2 << endl;    
    return 0;
}
```

输入：
1234567890↙

程序的输出结果是：
1234,567

说明`setw(4)`使得读入 s1 时，只读入 4 个字符，其后的`setw(3)`使得读入 s2 时只读入 3 个字符。

setw() 用于 cin 时，同样只影响下一次的输入。

### 调用cout的成员函数

ostream 类有一些成员函数，通过 cout 调用它们也能用于控制输出的格式，其作用和流操纵算子相同，如表 3 所示。



| 成员函数     | 作用相同的流操纵算子 | 说明                                                         |
| ------------ | -------------------- | ------------------------------------------------------------ |
| precision(n) | setprecision(n)      | 设置输出浮点数的精度为 n。                                   |
| width(w)     | setw(w)              | 指定输出宽度为 w 个字符。                                    |
| fill(c)      | setfill (c)          | 在指定输出宽度的情况下，输出的宽度不足时用字符 c 填充（默认情况是用空格填充）。 |
| setf(flag)   | setiosflags(flag)    | 将某个输出格式标志置为 1。                                   |
| unsetf(flag) | resetiosflags(flag)  | 将某个输出格式标志置为 0。                                   |

 

setf 和 unsetf 函数用到的`flag`，与 setiosflags 和 resetiosflags 用到的完全相同。

这些成员函数的用法十分简单。例如下面的三行程序：

```
cout.setf(ios::scientific);cout.precision(8);cout << 12.23 << endl;
```

输出结果是：
1.22300000e+001

28. 字符判断

```c++
#include <cctype>
isalpha('c');//是否是字母
isdigit('3');//是否是数字
isalnum('a');//是否是字母或数字
islower('b');//是否是小写字母
isupper('A');//是否是大写字母
```

29. cin和scanf读取失败后变量的表现

```c++
double a=123, b=456,c=789;//经测试int也是同样效果
cin>>a>>b>>c;//输入555 abc 777
cout<<a<<endl<<b<<endl<<c;//输出555 0 789，说明读取失败的那一个会被置0，后面的不变
cin>>a>>b>>c;//输入-.5abc 777 888
cout<<a<<endl<<b<<endl<<c;//输出-0.5 0 789，说明混合字符串的前半部分会被读入

int a=123, b=456,c=789;//经测试double也是同样效果
scanf("%d%d%d", &a, &b, &c);//输入555 abc 777
cout<<a<<endl<<b<<endl<<c;//输出555 456 789，说明从读取失败的那一个开始，后面的都不变
scanf("%d%d%d", &a, &b, &c);//输入-4.5 333 444
cout<<a<<endl<<b<<endl<<c;//输出-4 456 789，说明混合字符串的前半部分会被读入
```

30. sscanf和sprintf的用法

```c++
char a[50], b[50];
double temp;
sscanf(a, "%lf", &temp);//除了第一个参数为字符数组名，其他的和scanf相同
sprintf(b, "%.2f",temp);//除了第一个参数为字符数组名，其他的和printf相同
```

31. accumulate函数，累加

```c++
#include <numeric>
vector<double> v;
//第三个形参类型和返回值类型相同 ,所以这里第三个形参如果写0会出错
double sum = accumulate(v.begin(), v.end(), 0.0);
```

32. list用法

```c++
int a[4] = {1,2,3,4};
list<int> ls;
list<int> ls1(a, a+4);//使用序列初始化list
list<int> ls2(5, 300);//初始含5个300
ls.assign(a, a+3);//使用序列初始化list，会覆盖原链表
ls.assign(3, 100);//初始化为3个100，会覆盖原链表
ls.size();//返回元素个数
ls.clear();//删除所有元素
ls.empty();//若空则返回true
int f = ls.front();//返回第一个元素
int b = ls.back();//返回最后一个元素
ls.push_front(1);//在头部添加元素
ls.push_back(2);//在尾部添加元素
ls.pop_front();//删除头部元素
ls.pop_back();//删除尾部元素
ls.resize(5);//改变大小为5，新增的用0填充
ls.resize(7, 100);//改变大小为7，新增的用100填充
for(list<int>::iterator it=ls.begin(); it!=ls.end(); it++);//正向遍历
for(list<int>::reverse_iterator it=ls.rbegin(); it!=ls.rend(); it++);//反向遍历
ls.insert(pos, 123);//在pos迭代器的位置插入123，插入完成后迭代器指向未插入时的指定元素现在的位置
ls.insert(pos, 5, 456);//在pos迭代器的位置插入5个456
ls.insert(pos, a, a+3);//在pos迭代器位置插入制定范围的序列
ls.splice(pos, ls1);//在pos迭代器位置插入整个ls1，同时会使ls1清空
ls.splice(pos, ls1, it);//在pos迭代器位置插it指向的ls1中的元素，插入后it变得非法
ls.splice(pos, ls1, first, last);//在pos迭代器位置插ls1中[first,last)的元素,插入后ls1内相应元素被删除
it=ls.erase(it);//删除迭代器it指向的单个元素，原it变得非法，故不能直接++，函数返回值是下一个it，即指向代替被删除元素的位置的元素的it
it=ls.erase(first, last);//删除迭代器[first,last)范围内的元素， first和last变得非法；返回值it指向代替被删除范围内首元素first的位置的元素的it；而对于vector也是如此
ls.sort(可选cmp函数);//对链表排序，cmp函数可要可不要
ls.reverse();//将整个list倒转
ls.unique();//删除重复元素，要求链表有序
ls1.swap(ls2);//交换ls1和ls2
ls1.merge(ls2);//合并ls1和ls2，要求ls1和ls2已经有序，且ls2会被清空
ls.remove(1);//删去链表里所有的1
// list::unique的另一个重载函数----------------------------------------------
#include <iostream>
#include <cmath>
#include <list>
// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }
// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};
int main ()
{
  double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
                       12.77, 73.35, 72.25, 15.3,  72.25 };
  std::list<double> mylist (mydoubles,mydoubles+10);
  mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
                             // 15.3,  72.25, 72.25, 73.0,  73.35
  mylist.unique();           //  2.72,  3.14, 12.15, 12.77
                             // 15.3,  72.25, 73.0,  73.35
  mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
                                       // 15.3,  72.25, 73.0
  mylist.unique (is_near());           //  2.72, 12.15, 72.25
  std::cout << "mylist contains:";
  for (std::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
// list::merge的另一个重载函数-----------------------------------------------
#include <iostream>
#include <list>
// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }
int main ()
{
  std::list<double> first, second;
  first.push_back (3.1);
  first.push_back (2.2);
  first.push_back (2.9);
  second.push_back (3.7);
  second.push_back (7.1);
  second.push_back (1.4);
  first.sort();
  second.sort();
  first.merge(second);
  // (second is now empty)
  second.push_back (2.1);
  first.merge(second,mycomparison);
  std::cout << "first contains:";
  for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
// list::remove_if--------------------------------------------------------
#include <iostream>
#include <list>
// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }
// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};
int main ()
{
  int myints[]= {15,36,7,17,20,39,4,1};
  std::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1
  mylist.remove_if (single_digit);           // 15 36 17 20 39
  mylist.remove_if (is_odd());               // 36 20
  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
```

33. 以数组形式静态存储的二叉树寻根方法

```c++
struct node{
	int lchild = -1, rchild = -1;
}tree[100];
bool have[100] = {false}
//节点编号从0到n-1，输入时按节点编号顺序输入对应的左右孩子，若想找的根节点只要建立一个have数组，每组有效的左右孩子，把左右孩子对应的编号have[i] = true，因为输入时只有根节点编号不会作为其他节点的孩子节点被输入，故根节点的have[root]==false，只要找的have数组里值为false的编号就找到了根节点编号。
```

34. 在进行多个int与double的乘法运算时，最好把double写在前面或者把int强制转换成double，否则可能会因为两个int相乘而溢出导致结果错误。
35. 二维vector初始化

```c++
int m, n;
vector<vector<int>> matrix(m, vector<int>(n));
```

36. 数据类型的最大最小值

```c++
numeric_limits<double>::max();//最大值，double可替换为其他数据类型
numeric_limits<double>::min();//最小值，double可替换为其他数据类型
```

37. 读取指定行数的字符串的注意事项

```c++
/*面对这样的输入数据：
4
29
5
elo nov
tam
读取4行指定的字符串，可能最开始会想到这么写*/
int n;
cin>>n;
while(n--){
    string in;
    getline(cin, in);
    cout<<in;
}
//但是这样写发现会少读取一行，原因是因为cin>>n时4后的\n还在缓冲区，getline读取到\n就会认为是一行，从而读取到一行空字符（因为\n前面没有字符），而将getline(cin, in);换成cin>>in读取无分隔的字符串就不会有缺少读一行的问题，是因为cin会自动忽略空格、\n等空白字符，故4后面的\n被忽略了，若想解决这个问题则应这么写
int n;
cin>>n;
getchar();
while(n--){
    string in;
    getline(cin, in);
    cout<<in;
}
//使用getchar()来接收4后面的\n。但当使用了ios::sync_with_stdio(false)时，getchar函数会出现问题！这时可以用cin.get()函数来替换getchar
ios::sync_with_stdio(false);
int n;
cin>>n;
cin.get();
while(n--){
    string in;
    getline(cin, in);
    cout<<in;
}
//cin.get()的用法如下
char ch;
cin.get(ch);
ch = cin.get();
cin.get();//单独使用用于接收\n等空白字符
```

38. string可以和string、char数组、char相加

```c++
string a("str1"), b("str2");
char c = 'C', d[4] = "QwQ";
cout<<a+b<<endl<<a+c<<endl<<a+d<<endl;
cout<<c+a<<endl<<d+a<<endl;
a += c;
a += d;
cout<<a;
```

39. advance函数和distance函数

```c++
#include <algorithm>
list<int> ls;
for(int i=0; i<10; i++) ls.push_back(i);
auto it = ls.begin();
advance(it, 5);//作用是把it向前移动5个，相当于5次it++， 5还可以改成负数，代表相应的--
cout<<*it<<endl;//输出5
cout<<distance(it, ls.end());//输出5，即后一个迭代器减前一个迭代器得到的距离
```

40. +=、-=、*=和/=这类符号不会和后面的表达式产生优先级的冲突而使运算结果不合预期

```c++
int a = 10, b = 10;
int a = 10, b = 10;
a = a - 5 - 2;
b -= 5 - 2;
cout<<a<<endl;//输出3
cout<<b;//输出7
```

41. 判断在map中某个key及其映射是否存在的方法

```c++
map<int, int> mp;
//1.find函数，若找的则返回对应迭代器，否则返回mp.end()
mp<int, int>::iterator it = mp.find(3);
//2.count函数,若找的则返回1，否则返回0
int a = mp.find(4);
```

