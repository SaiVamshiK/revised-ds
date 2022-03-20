
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

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
    bool isLeaf(TreeNode* root)
    {
        if((!root->left)&&(!root->right))
        {
            return true;
        }
        return false;
    }
    int func(TreeNode *root,unordered_map<TreeNode*,int> &mp)
    {
        if(!root)
        {
            return 0;
        }
        if(isLeaf(root))
        {
            return (root->val);
        }
        if(mp.find(root)!=mp.end())
        {
            return mp[root];
        }
        int x=(root->val);
        int op1=func(root->left,mp)+func(root->right,mp);
        int op2=x;
        if((root->left)&&(root->left->left))
        {
            op2+=(func(root->left->left,mp));   
        }
        if((root->left)&&(root->left->right))
        {
            op2+=(func(root->left->right,mp));   
        }
        if((root->right)&&(root->right->left))
        {
            op2+=(func(root->right->left,mp));
        }
        if((root->right)&&(root->right->right))
        {
            op2+=(func(root->right->right,mp));   
        }
        return mp[root]=max(op1,op2);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> mp;
        return func(root,mp);
    }
};















