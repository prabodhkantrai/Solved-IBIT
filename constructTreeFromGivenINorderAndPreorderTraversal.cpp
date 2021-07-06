#include <bits/stdc++.h>
using namespace std;



treenode* helper(int *pr, int *in, int l, int r, int x){
	if(l>r || r<l) return NULL;

	treenode* node;
	node = treenode_new(*(pr+x));
	
    if(l==r) return node;
    
    int m;
    int i;
	for(i=l;i<=r;i++){
		if(*(in + i)==*(pr+x)) m=i;
	}

	node->left = helper(pr, in, l, m-1, x+1);
	node->right = helper(pr, in, m+1, r, x+m-l+1);

	return node;

}
  
treenode* buildTree(int* A, int n1, int* B, int n2) {
    return helper(A, B, 0, n1-1, 0);
}
 
int main(){


	return 0;
}