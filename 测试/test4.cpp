#include<bits/stdc++.h>
using namespace std;
struct Node{//�����
    int data,father,level;//Ȩֵ�����ڵ���pre�е��±ꡢ���
    //Node(int d,int f,int l):data(d),father(f),level(l){}
};
int main(){
	Node n1 = Node{1};
	//Node* n2 = new Node(2,2);
	cout<<n1.data<<n1.father<<n1.level<<endl;
	//cout<<n2->data<<n2->father<<n2->level<<endl;
}
