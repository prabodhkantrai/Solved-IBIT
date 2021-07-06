#include <bits/stdc++.h>
using namespace std;

    
    queue<int> V;
    
    void helper(TreeNode* root, queue<int> &V){
        if(root==nullptr){
            return;
        }

        helper(root->left, V);
        V.push(root->val);
        helper(root->right, V);
        
        return;
    }
    
    BSTIterator(TreeNode* root) {
        helper(root, V);
    }
    
    int next() {
        
        if(hasNext()){
            int c = V.front();
            V.pop();
            return c;
        }
        return -1;
    }
    
    bool hasNext() {
        if(V.size()>=1){
            return true;
        }
        return false;
    }

/* MORE OPTIMAL SOLUTION
     stack<TreeNode*> s;
BSTIterator::BSTIterator(TreeNode *root) {
    while(!s.empty())
    s.pop();
    TreeNode* curr = root;
    while(curr)
    {
        s.push(curr);
        curr = curr->left;
    }
}
bool BSTIterator::hasNext() {
    return !s.empty();
}


int BSTIterator::next() {
    int ans = s.top()->val;
    TreeNode* temp = s.top();
    s.pop();
    temp = temp->right;
    while(temp)
    {
        s.push(temp);
        temp = temp->left;
    }
    return ans;
}

*/

int main(){

	return 0;
}