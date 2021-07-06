#include <bits/stdc++.h>
using namespace std;

	void helper(TreeNode* root, unordered_map<int,int> &ms, int k){
		if(root==NULL){
			return;
		}

		helper(root->left, ms, k);
		ms[root->val] = k-root->val;
		helper(root->right, ms, k);

		return;
	}
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> ms;
        helper(root, ms, k);
        for(auto it = ms.begin();it!=ms.end();it++){
            if(ms.find(it->second)!=ms.end() && ms.find(it->second)!=it){
                return true;
            }
        }
        return false;
    }
 
int main(){

	return 0;
}