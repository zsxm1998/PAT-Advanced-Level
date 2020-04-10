#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
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
/******************************结束写代码******************************/


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
/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
/*string solution(string input) {
	string output = "";
	node* root = createtree(0, input.size()-1, input);
	inorder(root, output);
	return output;
}*/
/******************************结束写代码******************************/
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
