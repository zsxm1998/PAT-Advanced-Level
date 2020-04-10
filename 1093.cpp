#include <cstdio>
#include <cstring> 

char input[100001];
int mod = 1000000007;//此题输出要求对此数取模 

int main(){
	scanf("%s", input);
	int length = strlen(input);
	int lefthasP[length];
	memset(lefthasP, 0, sizeof(lefthasP));
	if(input[0] == 'P'){
		lefthasP[0] = 1;
	}
	for(int i=1; i<length; i++){
		if(input[i] == 'P'){
			lefthasP[i] = lefthasP[i-1] + 1;
		}
		else{
			lefthasP[i] = lefthasP[i-1];
		}
	}
	int righthasT[length], ans = 0;
	memset(righthasT, 0, sizeof(righthasT));
	if(input[length-1] == 'T'){
		righthasT[length-1] = 1;
	}
	for(int i=length-2; i>0; i--){
		if(input[i] == 'T'){
			righthasT[i] = righthasT[i+1] + 1;
		}
		else if(input[i] == 'A'){
			righthasT[i] = righthasT[i+1];
			ans = (lefthasP[i-1]*righthasT[i+1]+ans)%mod;
		}
		else{
			righthasT[i] = righthasT[i+1];
		}
	}
	printf("%d", ans);
} 
