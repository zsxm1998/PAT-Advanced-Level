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
bool hashtable[maxn];
                        
Node* init()            
{                        
    Node* node = new Node;
    node->x = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* buildtree(int il, int ir, int ll, int lr) //���Ҹ���һ�����������������ʱ 
{                                                //��������������һ����һ�����ڵ�  
    if(il > ir)                                //�����ڲ��������ʱ��һ���ȳ��� 
    {                                            //����˳��������������һ�������ȷ��ֶ������ĸ��ڵ�  
        return NULL;
    }
    Node* node = new Node;
    int i, j;
    for(j = ll; j <= lr; j++)
    {
        bool flag = false;
        for(i = il; i <= ir; i++)
        {
            if(inorder[i] == levelorder[j])
            {
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    hashtable[i] = true;
    node->left = buildtree(il, i-1, j+1, lr);
    node->right = buildtree(i+1, ir, j+1, lr);
    node->x = inorder[i]; 
    return node;
}

void pre(Node* root){
	if(root==NULL) return;
	cout<<root->x<<' ';
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
