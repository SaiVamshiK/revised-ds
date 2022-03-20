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
    TreeNode* invert(TreeNode *root)
    {
        if(root==NULL)
        {
            return NULL;
        }
        int data=root->val;
        TreeNode *ans=new TreeNode(data);
        ans->left=invert(root->right);
        ans->right=invert(root->left);
        return ans;
    }
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};
