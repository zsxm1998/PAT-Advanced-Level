#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005;

struct Node{//�����
    int data,father,level;//Ȩֵ�����ڵ���pre�е��±ꡢ���
    Node(int d=0,int f=-1,int l=0):data(d),father(f),level(l){}
};

Node pre[MAXN];
int in[MAXN];
void buildTreeFromPreAndIn(int prel,int inl,int inr,int father,int level){//ȷ��ÿ�����ĸ��ڵ�����
    if(inl>inr)
        return;
    int i=inl;
    while(i<=inr&&in[i]!=pre[prel].data)
        ++i;
    int numl = i-inl;
    pre[prel]=Node(pre[prel].data,father,level);//ȷ����ǰ���������ĸ��ڵ�����
    buildTreeFromPreAndIn(prel+1,inl,i-1,prel,level+1);//�ݹ鴦��������
    buildTreeFromPreAndIn(prel+numl+1,i+1,inr,prel,level+1);//�ݹ鴦��������
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
        for(int i=0;i<n;++i){//�ҵ����������pre�����е��±�
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
            bool flag=true;//true��ʾa����ȸ���
            if(pre[ia].level<pre[ib].level){//��iaָ����ȸ���Ľ��
                swap(ia,ib);
                flag=false;
            }
            while(pre[ia].level>pre[ib].level)//�����ߵ�����ͬһ���
                ia=pre[ia].father;
            if(ia==ib){
                printf("%d is an ancestor of %d.\n",pre[ia].data,flag?a:b);
            }else{
                while(ia!=ib){//ia,ibͬʱ���ϵ�����ֱ������ָ��ͬһ���
                    ia=pre[ia].father;
                    ib=pre[ib].father;
                }
                printf("LCA of %d and %d is %d.\n",a,b,pre[ia].data);
            }
        }
    }
    return 0;
}

