#include <bits/stdc++.h>
using namespace std;
void helper(TreeNode* A, vector<int> &V){
	if(A==nullptr) return;

	V.push_back(A);

	helper(A->left);
	helper(A->right);

	return;
}

void flatten(TreeNode* A){
	/*if(!A->left && !A->right) return A;
    TreeNode *l, *r;
	if(A->left){
		l = helper(A->left);
	}

	if(A->right){
		r = helper(A->right); 
	}
	

	if(!A->left) A->right = r;
	else if(!A->right) A->right = l;
	else{
		A->right = l;
		l->right = r;
	}
	A->left = nullptr;

	return A;*/

	vector<TreeNode*> V;
	helper(A,V);
	for(int i=0;i<V.size()-1;i++){
		V[i]->right = V[i+1];
		V[i]->left = nullptr;
	}

	return;
}
 
int main(){

	return 0;
}