#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int heap[MAXN];//�󶥶� 

void downAdjust(int low, int high){//���µ��� 
	int temp = heap[low];
	for(int i=low*2; i<=high; i*=2){
		if(i<high && heap[i]<heap[i+1]) i++;
		if(heap[i]>temp){
			heap[low] = heap[i];
			low = i;
		}
		else{
			break;
		}
	}
	heap[low] = temp;
}

void upAdjust(int low, int high){//���ϵ��� 
	int temp = heap[high];
	for(int i=high/2; i>=low && heap[i]<temp; i/=2){
		heap[high] = heap[i];
		high = i;
	}
	heap[high] = temp;
} 

void createHeap(int n){//���� 
	for(int i=n/2; i>0; i--){
		downAdjust(i, n);
	}
}

void deleteTop(int &n){//ɾ���Ѷ�Ԫ�� 
	heap[1] = heap[n--];
	downAdjust(1, n);
} 

void insert(int x, int &n){//���Ԫ��x 
	heap[++n] = x;
	upAdjust(1, n);
} 

void heapSort(int n){//������ 
	createHeap(n);
	for(int i=n; i>1; i++){
		swap(heap[1], heap[i]);
		downAdjust(1, i-1);
	}
}

int main(){
	return 0;
} 
