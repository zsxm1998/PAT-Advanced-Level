#include <cstdio>
#include <cmath>

int main(){
	int L, K;
	scanf("%d%d", &L, &K);
	char N[L+1];
	scanf("%s", N);
	for(int i=0; i<=L-K; i++){
		int number = 0;
		for(int s=0; s<K; s++){
			number *= 10;
			number += N[i+s] - 48;
		}
		bool flag = true;
		for(int t=2; t<floor(sqrt((double)number)); t++){
			if(number%t == 0){
				flag = false;
				break;
			}
		}
		if(flag){
			for(int x=0; x<K; x++){
				printf("%c", N[i+x]);
			}
			return 0;
		}
	}
	printf("404");
	return 0;
}
