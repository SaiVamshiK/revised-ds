/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* func(TreeNode *root,TreeNode *x,TreeNode *y)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==x->val||(root->val==y->val))
        {
            return root;
        }
        TreeNode *left=func(root->left,x,y);
        TreeNode *right=func(root->right,x,y);
        if(left==NULL)
        {
            return right;
        }
        if(right==NULL)
        {
            return left;
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return func(root,p,q);
    }
};
