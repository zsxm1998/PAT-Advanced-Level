#include<bits/stdc++.h>
using namespace std;
struct Node{//结点类
    int data,father,level;//权值、父节点在pre中的下标、深度
    //Node(int d,int f,int l):data(d),father(f),level(l){}
};
int main(){
	Node n1 = Node{1};
	//Node* n2 = new Node(2,2);
	cout<<n1.data<<n1.father<<n1.level<<endl;
	//cout<<n2->data<<n2->father<<n2->level<<endl;
}
