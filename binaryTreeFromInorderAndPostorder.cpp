#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        /*TreeNode() : val(0), left(nullptr), right(nullptr) {}*/
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        /*TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}*/
  };

TreeNode* helper(vector<int> &in, vector<int> &po, int l, int r, int x){
	if(l>r) return NULL;

	TreeNode* node = new TreeNode(po[x--]);

	auto m = find(in.begin() + l, in.begin() + r, node->val);

	int diff = m - (in.begin());

	//cout<<diff<<endl;

	node->left = helper(in, po, l, diff-1, x - (r - diff));
	node->right = helper(in, po, diff+1, r, x);

	return node;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size();
    if(n == 0) return nullptr;
    
    return helper(A, B, 0, n-1, n-1);
}
 
void printTree(TreeNode* temp){
	if(temp==nullptr) return;

	printTree(temp->left);
	cout<<temp->val;
	printTree(temp->right);

	return;
}

int main(){

	vector<int> A = {1};
	vector<int> B = {1};

	TreeNode* temp = solve(A,B);

	printTree(temp);

	return 0;
}