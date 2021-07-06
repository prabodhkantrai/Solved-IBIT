#include <bits/stdc++.h>
using namespace std;


TreeNode* invertTree(TreeNode* A) {
        if(!A) return nullptr;
        if(!A->left && !A->right) return A;
        
        TreeNode *temp1 = nullptr;
        TreeNode *temp2 = nullptr;
        

	    if(A->right) temp1 = invertTree(A->right);
	    if(A->left) temp2 = invertTree(A->left);
        
        A->left = temp1;
        A->right = temp2;

	    return A;
}

int main(){

	return 0;
}