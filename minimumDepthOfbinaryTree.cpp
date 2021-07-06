#include <bits/stdc++.h>
using namespace std;

int mini;
void helper(TreeNode* A, int row){
	if(!A->left && !A->right){
		if(mini>row+1){
			mini = row+1;
		}
	}

	if(A->left) helper(A->left, row+1);
	if(A->right) helper(A->right, row+1);

	return;
}

bool minDepth(TreeNode* A){
	mini = INT_MAX;
	helper(A, 0);
	return mini;
}
 
int main(){

	return 0;
}