//������ʼ�и����Ե��������Ϊ���λת��Ϊ���λ��ʱ���п������int��Χ��
//��Ȼ������ת������ı�����long long���������ʱ����Ѿ���Ϊ�����������
/*#include <iostream>
using namespace std;
int main() {
    int a, b, c, d, e, f;
    scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f);
    long long num = c + b * 29 + a * 29 * 17 + f + e * 29 + d * 29 * 17;//�����a��dǿת��long long��AC�ˣ�˳��һ�ᣬ����ֱ��һ����ʽ�ͺã����÷ǵ÷ֱ�ת����������������� 
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

