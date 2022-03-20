
Given a binary tree T, find the maximum path sum.

The path may start and end at any node in the tree.

Input Format:

The first and the only argument contains a pointer to the root of T, A.
Output Format:

Return an integer representing the maximum sum path.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int func(TreeNode *root,int &ans)
{
    if(!root)
    {
        return 0;
    }
    int left_max=func(root->left,ans);
    int right_max=func(root->right,ans);
    int cur=(root->val);
    ans=max(ans,max(cur,max(cur+left_max+right_max,max(left_max+cur,right_max+cur))));
    return max(cur,max(left_max+cur,right_max+cur));
}
int Solution::maxPathSum(TreeNode* root) {
    if((!root))
    {
        return 0;
    }
    int ans=INT_MIN;
    func(root,ans);
    return ans;
}

