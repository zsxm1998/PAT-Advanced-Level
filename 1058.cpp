//这个题最开始有个测试点出错是因为最高位转换为最低位的时候有可能溢出int范围，
//虽然最后接收转换结果的变量是long long，但运算的时候就已经因为溢出而出错了
/*#include <iostream>
using namespace std;
int main() {
    int a, b, c, d, e, f;
    scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f);
    long long num = c + b * 29 + a * 29 * 17 + f + e * 29 + d * 29 * 17;//这里给a和d强转成long long就AC了；顺便一提，这里直接一个等式就好，不用非得分别转换成两个变量再相加 
    long long g = num % 29;
    num /= 29;
    long long h = num % 17;
    num /= 17;
    printf("%lld.%lld.%lld", num, h, g);
    return 0;
} */
#include <bits/stdc++.h>
using namespace std;
struct currency{
	long long ga, si, kn;
	friend currency operator+(const currency &a, const currency &b){
		currency c;
		long long ckn = a.kn + b.kn;
		int carryk = ckn / 29;
		c.kn = ckn % 29;
		long long csi = a.si + b.si + carryk;
		int carrys = csi / 17;
		c.si = csi % 17;
		c.ga = a.ga + b.ga + carrys;
		return c;
	}
};
int main(){
	currency a, b;
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &a.ga, &a.si, &a.kn, &b.ga, &b.si, &b.kn);
	currency c = a + b;
	printf("%lld.%lld.%lld", c.ga, c.si, c.kn);
	return 0;
}

