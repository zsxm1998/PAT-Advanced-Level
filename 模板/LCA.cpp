#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005;

struct Node{//结点类
    int data,father,level;//权值、父节点在pre中的下标、深度
    Node(int d=0,int f=-1,int l=0):data(d),father(f),level(l){}
};

Node pre[MAXN];
int in[MAXN];
void buildTreeFromPreAndIn(int prel,int inl,int inr,int father,int level){//确定每个结点的父节点和深度
    if(inl>inr)
        return;
    int i=inl;
    while(i<=inr&&in[i]!=pre[prel].data)
        ++i;
    int numl = i-inl;
    pre[prel]=Node(pre[prel].data,father,level);//确定当前子树根结点的父节点和深度
    buildTreeFromPreAndIn(prel+1,inl,i-1,prel,level+1);//递归处理左子树
    buildTreeFromPreAndIn(prel+numl+1,i+1,inr,prel,level+1);//递归处理右子树
}
int main(){
	int n, m; 
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;++i)
        scanf("%d",&in[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&pre[i].data);
    buildTreeFromPreAndIn(0,0,n-1,-1,1);
    for(int i=0;i<m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        int ia=n,ib=n;
        for(int i=0;i<n;++i){//找到两个结点在pre数组中的下标
            if(pre[i].data==a)
                ia=i;
            if(pre[i].data==b)
                ib=i;
        }
        if(ia==n&&ib==n){
            printf("ERROR: %d and %d are not found.\n",a,b);
        }else if(ia==n){
            printf("ERROR: %d is not found.\n",a);
        }else if(ib==n){
            printf("ERROR: %d is not found.\n",b);
        }else{
            bool flag=true;//true表示a的深度更大
            if(pre[ia].level<pre[ib].level){//让ia指向深度更大的结点
                swap(ia,ib);
                flag=false;
            }
            while(pre[ia].level>pre[ib].level)//将二者调整到同一深度
                ia=pre[ia].father;
            if(ia==ib){
                printf("%d is an ancestor of %d.\n",pre[ia].data,flag?a:b);
            }else{
                while(ia!=ib){//ia,ib同时向上调整，直至二者指向同一结点
                    ia=pre[ia].father;
                    ib=pre[ib].father;
                }
                printf("LCA of %d and %d is %d.\n",a,b,pre[ia].data);
            }
        }
    }
    return 0;
}

