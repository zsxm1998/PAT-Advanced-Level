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

/*这个重建的方法利用了层序遍历序列中父子节点有先后顺序的特点。
当我给你一个二叉树的中序遍历时 
这个中序遍历遍历一定有一个根节点  
体现在层序遍历上时它一定先出现 
所以顺序遍历层序遍历，一定可以先发现二叉树的根节点*/
Node* buildTreeFromInAndLev(int inl, int inr, int levl, int levr)
{
    if(inl > inr)//若中序序列长度为0则返回NULL
    {
        return NULL;
    }
    int i, j;
    for(j = levl; j <= levr; j++)//在层序序列中从前往后找第一个在中序序列中出现的节点，为当前树的根节点 
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

void preorder(Node* root){//先序输出 
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
