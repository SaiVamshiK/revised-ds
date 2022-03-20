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
    bool isMirror(TreeNode *l,TreeNode *r)
    {
        if(l==NULL&&r==NULL)
        {
            return true;
        }
        if(l==NULL&&r!=NULL)
        {
            return false;
        }
        if(r==NULL&&l!=NULL)
        {
            return false;
        }
        if(l->val==r->val)
        {
            bool ans1=isMirror(l->left,r->right);
            bool ans2=isMirror(r->left,l->right);
            if(ans1&&ans2)
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        return isMirror(root->left,root->right);
    }
};
