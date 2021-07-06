#include <bits/stdc++.h>
using namespace std;
TreeNode* can;

bool helper(TreeNode* A, TreeNode *p, TreeNode* q, bool flag){
	/*if(A==nullptr) return false;

	if(flag && (A==p || A==q)) return true;

	if(!flag){
		if(A==p || A==q) flag = true;	
		can = A;
	}
	if(flag==false){
		if(!helper(A->left, p, q, flag) && !helper(A->right, p, q, flag)) return false;
		else return true;
	}
	else{
		if(helper(A->left, p, q, flag) || helper(A->right, p, q, flag)) return true;
	}

	return false;*/ 
}


TreeNode* lowestCommonAncestor(TreeNode* A, TreeNode* p, TreeNode* q){
	/*can = A;
	helper(A,p,q,false);
	return can;*/

	if(A==nullptr) return;

	if(A==p || A==q) return A;


	TreeNode* l = lowestCommonAncestor(A->left, p, q);
	TreeNode* r = lowestCommonAncestor(A->right,p, q);

	if(l&&r) return A;
	return (l)? l : r; 
}
 
int main(){

	return 0;
}