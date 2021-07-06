#include <bits/stdc++.h>
using namespace std;

void helper(TreeNode* A, int row){
	if(A==nullptr) return;

	if(row>mx) mx = row;

	if(A->left) helper(A->left, row+1);
	if(A->right) helper(A->right, row+1);

	return;
}

int solve(TreeNode* A){
	mx=-1;
	helper(A, 0);
	return mx;
}
 
int main(){

	return 0;
}