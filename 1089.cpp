#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ori, par;
bool insertion(vector<int> o, vector<int> p, vector<int> &output) {
    bool flag = false;
    for(int i=1; i<n; i++) {
        int temp = o[i], j;
        for(j=i-1; j>=0&&o[j]>temp; j--) o[j+1] = o[j];
        o[j+1] = temp;
        if(flag) {
            output = o;
            return flag;
        }
        if(o == p) flag = true;
    }
    return flag;
}
bool mergesort(vector<int> o, vector<int> p, vector<int> &output) {
    bool flag = false;
    auto bg = o.begin();
    int step = 1;
    do {
        step *= 2;
        for(int i=0; i<o.size(); i += step) {
            if(i+step < o.size()) sort(bg+i, bg+i+step);
            else sort(bg+i, o.end());
        }
        if(flag) {
            output = o;
            return flag;
        }
        if(o == p) flag = true;
    } while(step < o.size());
    return flag;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin>>n;
    ori.resize(n), par.resize(n);
    for(int i=0; i<n; i++) cin>>ori[i];
    for(int i=0; i<n; i++) cin>>par[i];
    vector<int> output(n);
    if(insertion(ori, par, output)) {
        for(int i=0; i<n; i++) cout<<(i?" ":"Insertion Sort\n")<<output[i];
    } else if(mergesort(ori, par, output)) {
        for(int i=0; i<n; i++) cout<<(i?" ":"Merge Sort\n")<<output[i];
    }
    return 0;
}
