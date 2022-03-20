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
    void flatten(TreeNode* root) {
        if(root==NULL)
        {
            return ;
        }
        flatten(root->left);
        flatten(root->right);
        if(root->left)
        {
            TreeNode *t=root->left;
            TreeNode *x=t;
            while(x->right)
            {
                x=x->right;
            }
            root->left=NULL;
            x->right=root->right;
            root->right=t;
        }
    }
};
