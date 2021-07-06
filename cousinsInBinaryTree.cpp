#include <bits/stdc++.h>
using namespace std;

int helper(TreeNode* A, int B, int row){
	if(A==nullptr) return;

	if(A->val==B){
		return row
	}
}

bool isCousins(TreeNode* root, int x, int y){
	queue<pair<int,TreeNode*>> qp;
	int one, two;
	qp.push(make_pair(0,root));
	while(qp.size()){
		auto [row, node] = qp.front();
		qp.pop();

		if(node->val == x) one = row;
		if(node->val == y) two = row;

		if(node->left && node->right && ((node->left->val==x && node->right->val == y) || (node->left->val==y && node->right->val == x))) return false;

		if(node->left){
			qp.push(make_pair(row+1, node->left));
		}

		if(node->right){
			qp.push(make_pair(row+1, node->right));
		}
	}

	if(one!=two) return false;
	return true;
}
 
int main(){

	return 0;
}