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
bool hashtable[maxn];   //���levelorder��ĳ�����Ƿ񱻼��������� 
                        //���û��hashtable, �����д�������ֵ��ȵĵ�ʱ �� 
Node* init()            //���ܵ����ڲ����������ֵͬ��������ǰ��ĵ㱻�������Σ�����ĵ� 
{                        //û�б��������Ӷ��������� 
    Node* node = new Node;
    node->x = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* buildtree(int il, int ir, int ll, int lr) //���Ҹ���һ�����������������ʱ 
{                                                //��������������һ����һ�����ڵ�  
    if(il == ir)                                //�����ڲ��������ʱ��һ���ȳ��� 
    {                                            //����˳��������������һ�������ȷ��ֶ������ĸ��ڵ�  
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
