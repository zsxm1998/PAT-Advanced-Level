#include<iostream>
#include<cstdio>
using namespace std;
const int INF = 0x3fffffff;
const int maxn = 10010;

struct Node
{
    int x;
    Node *left, *right;
};

Node* root;
int levelorder[maxn], inorder[maxn];
int n;
bool hashtable[maxn];   //标记levelorder中某个点是否被加入了树中 
                        //如果没有hashtable, 当树中存在两个值相等的点时 ， 
Node* init()            //可能导致在层序遍历中相同值的两个点前面的点被遍历两次，后面的点 
{                        //没有被遍历，从而建树错误 
    Node* node = new Node;
    node->x = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* buildtree(int il, int ir, int ll, int lr) //当我给你一个二叉树的中序遍历时 
{                                                //这个中序遍历遍历一定有一个根节点  
    if(il == ir)                                //体现在层序遍历上时它一定先出现 
    {                                            //所以顺序遍历层序遍历，一定可以先发现二叉树的根节点  
        Node* node = new Node;
        node->x = inorder[il];
        hashtable[il] = true;
        return node;
    }
    Node* node = new Node;
    int i, j;
    for(j = ll; j <= lr; j++)
    {
        bool flag = false;
        for(i = il; i <= ir; i++)
        {
            if(inorder[i] == levelorder[j]&&hashtable[i] == false)
            {
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    node->left = buildtree(il, i-1, j+1, lr);
    node->right = buildtree(i+1, ir, j+1, lr);
    node->x = inorder[i];
    hashtable[i] = true;
    return node;
}

void pre(Node* root){
	cout<<root->x;
	pre(root->left);
	pre(root->right);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for(int i = 0; i < n; i++) scanf("%d", &levelorder[i]);
    root = buildtree(0, n-1, 0, n-1);
    pre(root);
    return 0;
}
