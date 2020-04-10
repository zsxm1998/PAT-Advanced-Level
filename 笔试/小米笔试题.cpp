#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^ 
******************************��ʼд����******************************/
string solution(string input) {
	string output = "";
	stack<char> st;
	for(int i = 0; i<input.size(); i++){
		if(input[i] == ')'){
			if(input[i-1] != ')' && input[i-1] != ','){
				output += st.top();
				st.pop();
			}
		}else if(input[i] == ','){
			if(input[i-1] == '(' || input[i-1] == ')'){
				output += st.top();
				st.pop();
			}else{
				output += st.top();
				st.pop();
				output += st.top();
				st.pop();
			}
		}else if(input[i] != '('){
			st.push(input[i]);
		}
	}
	return output;
}
/******************************����д����******************************/


int main() {
    string res;

    string _input;
    getline(cin, _input);
    
    res = solution(_input);
    cout << res << endl;
    
    return 0;
}



/*#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <string>
#include <cstring>

using namespace std;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

node* createtree(int left, int right, string &in){
	if(left>right){
		return NULL;
	}
	node* root = new node;
	root->data = in[left];
	int lefthas[right-left+1];
	memset(lefthas, 0, sizeof(lefthas));
	for(int i=1; i<right-left+1; i++){
		if(in[i+left] == '('){
			lefthas[i] = lefthas[i-1] + 1;
		}
		else{
			lefthas[i] = lefthas[i-1];
		}
	}
	int righthas[right-left+1] ,mid = 0;
	memset(righthas, 0, sizeof(righthas));
	righthas[right-left] = 1;
	for(int i=right-left-1; i>0; i--){
		if(in[i+left] == ')'){
			righthas[i] = righthas[i+1] + 1;
		}
		else{
			righthas[i] = righthas[i+1];
			if(in[i+left] == ',' && lefthas[i]==righthas[i]){
				mid = i+left;
			}
		}
	}
	root->lchild = createtree(left+2, mid-1, in);
	root->rchild = createtree(mid+1, right-1, in);
	return root;
}

void inorder(node* root, string &out){
	if(root == NULL){
		return;
	}
	inorder(root->lchild, out);
	out += root->data; //to_string(root->data);
	inorder(root->rchild, out);
}*/
/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^ 
******************************��ʼд����******************************/
/*string solution(string input) {
	string output = "";
	node* root = createtree(0, input.size()-1, input);
	inorder(root, output);
	return output;
}*/
/******************************����д����******************************/
/*

int main() {
    string res;

    string _input;
    getline(cin, _input);
    
    res = solution(_input);
    cout << res << endl;
    
    return 0;
}
*/
