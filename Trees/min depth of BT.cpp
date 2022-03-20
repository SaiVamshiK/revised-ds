/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    if(A==NULL)
    {
        return 0;
    }
    int ans1=INT_MAX,ans2=INT_MAX;
    if(A->left)
    {
        ans1=minDepth(A->left);
    }
    if(A->right)
    {
        ans2=minDepth(A->right);
    }
    if(!A->left&&(!A->right))
    {
        return 1;
    }
    return 1+min(ans1,ans2);
}

