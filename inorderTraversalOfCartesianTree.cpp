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

  int mx, m;

TreeNode* helper(vector<int> &A, int l, int r){

	if(l>r || r<l) return nullptr;
	
	

	int mx = -1;
	int m;

	for(int i = l; i <= r ; i++){
		if(A[i]>mx){
			mx = A[i];
			m = i;
		}
	}

	TreeNode* node  = new TreeNode(mx);
	
	if(l==r) return node;

	node->left = helper(A, l, m-1);
	node->right = helper(A, m+1, r);

	return node;
}

TreeNode* solve(vector<int> &A){

	int l = 0;
	int r = A.size()-1;

	TreeNode* root = helper(A, l, r);

	return root;
}


void printTree(TreeNode* temp){
	if(temp==nullptr) return;

	printTree(temp->left);
	cout<<temp->val;
	printTree(temp->right);

	return;
}
 
int main(){

	vector<int> A = {1,2,3};

	TreeNode* temp  = solve(A);

	printTree(temp);




	return 0;
}