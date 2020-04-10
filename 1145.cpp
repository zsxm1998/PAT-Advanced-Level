#include <cstdio>

int giveprime(int x){//return the smallest prime which is larger than x
	bool notfinded = true;
	int y = x-1;
	while(notfinded){
		y++;
		notfinded = false;
		for(int i=2; i*i<=y; i++){
			if(y%i == 0){
				notfinded = true;
				break;
			}
		}
	}
	return y;
}

int main(){
	int MSize, N, M, TSize;
	scanf("%d%d%d", &MSize, &N, &M);
	TSize = giveprime(MSize);
}
