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
    int solve(TreeNode *root,int &res)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=solve(root->left,res);
        int r=solve(root->right,res);
        int temp=max(max(l,r)+root->val,max(root->val,0));
        int ans=max(root->val+l+r,max(root->val,max(l+root->val,r+root->val)));
        res=max(res,ans);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        solve(root,res);
        return res;
    }
};
