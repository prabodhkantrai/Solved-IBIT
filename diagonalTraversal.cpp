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

void solve(TreeNode* root, map<int, vector<int>> &mp, int row){
	if(root==nullptr) return;

	if(mp.find(row)==mp.end()) mp[row] = {root->val};
	else mp[row].push_back(root->val);

	solve(root->left, mp, row+1);
	solve(root->right, mp, row);
}

vector<vector<int>> traverse(TreeNode* A){
	vector<vector<int>> G;
	map<int, vector<int>> mp;
	solve(A, mp, 0);

	for(auto it : mp){
		G.push_back(it.second);
	}

	return G;
}
 
int main(){


	TreeNode* temp6 = new TreeNode(13);
	TreeNode* temp5 = new TreeNode(7);
	TreeNode* temp4 = new TreeNode(4);
	TreeNode* temp3 = new TreeNode(1);
	TreeNode* temp7 = new TreeNode(3, temp3, nullptr);
	TreeNode* temp8 = new TreeNode(6, temp4, temp5);
	TreeNode* temp9 = new TreeNode(14, temp6, nullptr);
	TreeNode* temp10 = new TreeNode(10, temp8, temp9);
	//TreeNode* temp2 = new TreeNode(2,nullptr,temp3);
	TreeNode* temp1 = new TreeNode(8, temp7, temp10);
	vector<vector<int>> G = traverse(temp1);

	for(auto it : G){
		for(int c : it){
			cout<<c<<" ";
		}
		cout<<endl;
	}


	return 0;
}