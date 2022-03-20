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
    bool func(TreeNode *a,TreeNode *b)
    {
        if(a==NULL&&b==NULL)
        {
            return true;
        }
        if(a==NULL&&b!=NULL)
        {
            return false;
        }
        if(b==NULL&&a!=NULL)
        {
            return false;
        }
        if(a->val==b->val)
        {
            bool ans1=func(a->left,b->left);
            bool ans2=func(a->right,b->right);
            if(ans1&&ans2)
            {
                return true;
            }
            return false;
        }else{
            return false;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return func(p,q);
    }
};
