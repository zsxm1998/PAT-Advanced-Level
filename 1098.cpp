#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ori, par;
bool insertion(vector<int> o, vector<int> p, vector<int> &output){
	bool flag = false;
	for(int i=1; i<n; i++){
		int temp = o[i], j;
		for(j=i-1; j>=0&&o[j]>temp; j--) o[j+1] = o[j];
		o[j+1] = temp;
		if(flag){
			output = o;
			return flag;
		}
		if(o == p) flag = true;
	}
	return flag;
}
bool isequal(int a[], int b[]){
	for(int i=1; i<=n; i++) if(a[i] != b[i]) return false;
	return true;
}
void adjustdown(int a[], int p, int max){
	int temp = a[p];
	for(int i=p*2; i<=max; i*=2){
		if(i<max&&a[i]<a[i+1]) i++;
		if(a[i]>temp){
			a[p] = a[i];
			p = i;
		}else break;
	}
	a[p] = temp;
}
bool heap(vector<int> o, vector<int> p, vector<int> &output){
	bool flag = false;
	int orig[n+1], part[n+1];
	orig[0] = 0, part[0] = 0;
	for(int i=1; i<=n; i++) orig[i] = o[i-1], part[i] = p[i-1];
	for(int i=n/2; i>0; i--) adjustdown(orig, i, n);
	for(int i=n; i>1; i--){
		swap(orig[i], orig[1]);
		adjustdown(orig, 1, i-1);
		if(flag){
			for(int i=0; i<n; i++) output[i] = orig[i+1];
			return flag;
		}
		if(isequal(orig, part)) flag = true;
	}
	return flag;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	ori.resize(n), par.resize(n);
	for(int i=0; i<n; i++) cin>>ori[i];
	for(int i=0; i<n; i++) cin>>par[i];
	vector<int> output(n);
	if(insertion(ori, par, output)){
		for(int i=0; i<n; i++) cout<<(i?" ":"Insertion Sort\n")<<output[i];
	}else{
		heap(ori, par, output);
		for(int i=0; i<n; i++) cout<<(i?" ":"Heap Sort\n")<<output[i];
	}
	return 0;
}

