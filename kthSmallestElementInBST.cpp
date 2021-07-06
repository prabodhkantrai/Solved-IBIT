#include <bits/stdc++.h>
using namespace std;

void helper(TreeNode* root, int k, vector<int> &V){
	/*(root->left == NULL && root->right == NULL){
		V.push_back(root->val);
		return;
	}

	helper(root->left, k, V);
	if(V.size()==k) return;
	V.push_back(root->val);
	if(V.size()==k) return;
	helper(root->right, k, V);

	return;*/

	if(root===NULL){
		return;
	}

	helper(root->left, k, V);
	V.push_back(root->val);
	helper(root->right, k, V);

	return;
}

int kthSmallest(TreeNode* root, int k) {
		vector<int> V;
        helper(root, k, V);
        return V[k-1];
    }
 
int main(){

	return 0;
}