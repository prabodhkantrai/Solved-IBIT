#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

int flag;

int height(TreeNode* root){
	if(flag==false) return -1;
	if(root==nullptr) return 0;

	int l = height(root->left);
	int r = height(root->right);

	if(abs(l-r)>1) flag = 0;

	return max(l, r) + 1;

	
	return 0;
}

int isBalanced(TreeNode* root){
	flag=1;
	height(root);
	return flag;
}
 
int main(){
	TreeNode* temp3 = new TreeNode(3);
	TreeNode* temp2 = new TreeNode(2,nullptr,temp3);
	TreeNode* temp1 = new TreeNode(1, nullptr, temp2);
	cout<<isBalanced(temp1);
	return 0;
}