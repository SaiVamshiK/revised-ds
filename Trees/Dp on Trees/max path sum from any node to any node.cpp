/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=INT_MIN;
    int func(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=func(root->left);
        int r=func(root->right);
        ans=max(ans,max(root->val,max(l+root->val,max(r+root->val,l+r+root->val))));
        return max(l+root->val,max(r+root->val,max(root->val,0)));
    }
    int maxPathSum(TreeNode* root) {
        func(root);
        return ans;
    }
};



