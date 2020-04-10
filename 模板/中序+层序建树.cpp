#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int MAXN = 10010;

struct Node
{
    int data;
    Node *lchild, *rchild;
};

int level[MAXN], in[MAXN];

/*����ؽ��ķ��������˲�����������и��ӽڵ����Ⱥ�˳����ص㡣
���Ҹ���һ�����������������ʱ 
��������������һ����һ�����ڵ�  
�����ڲ��������ʱ��һ���ȳ��� 
����˳��������������һ�������ȷ��ֶ������ĸ��ڵ�*/
Node* buildTreeFromInAndLev(int inl, int inr, int levl, int levr)
{
    if(inl > inr)//���������г���Ϊ0�򷵻�NULL
    {
        return NULL;
    }
    int i, j;
    for(j = levl; j <= levr; j++)//�ڲ��������д�ǰ�����ҵ�һ�������������г��ֵĽڵ㣬Ϊ��ǰ���ĸ��ڵ� 
    {
        bool flag = false;
        for(i = inl; i <= inr; i++)
        {
            if(in[i] == level[j])
            {
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    Node* node = new Node;
    node->data = in[i]; 
    node->lchild = buildTreeFromInAndLev(inl, i-1, j+1, levr);
    node->rchild = buildTreeFromInAndLev(i+1, inr, j+1, levr);
    return node;
}

void preorder(Node* root){//������� 
	if(root==NULL) return;
	cout<<root->data<<' ';
	preorder(root->lchild);
	preorder(root->rchild);
}

int main()
{
    int n;
	scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    for(int i = 0; i < n; i++) scanf("%d", &level[i]);
    Node* root = buildTreeFromInAndLev(0, n-1, 0, n-1);
    preorder(root);
    return 0;
}
