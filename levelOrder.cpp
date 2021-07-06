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

vector<vector<int>> solve(TreeNode* A){
	if(A==nullptr) return {};
	 vector<vector<int>> res;
	queue<pair<TreeNode*,int>> q;
	q.push({A,0});

	while(!q.empty()){
		auto top = q.front();
		auto node = top.first;
		int level = top.second;
        q.pop();

		if(res.size()<level+1){
			res.push_back({node->val});	
		}
		else{
			res[level].push_back(node->val);
		}

		if(node->left) q.push({node->left,level+1});
		if(node->right) q.push({node->right,level+1});
	}

	return res;
}	
 
int main(){
	TreeNode* five = new TreeNode(15);
	TreeNode* seven = new TreeNode(7);
	TreeNode* twen = new TreeNode(20, five, seven);
	TreeNode* nine = new TreeNode(9);
	TreeNode* three = new TreeNode(3, nine, twen);

	for(auto it : solve(three)){
		for( int c : it) cout<<c<<" ";
			cout<<endl;
	}

	return 0;
}