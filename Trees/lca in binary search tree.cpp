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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
        {
            return NULL;
        }
        int d1=p->val,d2=q->val,qwe=root->val;
        if((d1<qwe)&&(d2<qwe))
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        if((d1>qwe)&&(d2>qwe))
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};
