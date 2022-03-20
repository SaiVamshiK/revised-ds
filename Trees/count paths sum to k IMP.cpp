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
    int total=0;
    void func(TreeNode *root,TreeNode *prev)
    {
        if(root==NULL)
        {
            return ;
        }
        if(prev==NULL)
        {
            prev=root;
            func(root->left,prev);
            func(root->right,prev);
            return ;
        }
        root->val+=prev->val;
        func(root->left,root);
        func(root->right,root);
        return ;
    }
    void solve(TreeNode *root,unordered_map<int,int> &mp,int sum)
    {
        if(root==NULL)
        {
            return ;
        }
        if(mp.find(root->val-sum)!=mp.end())
        {
            total+=mp[root->val-sum];
        }
        mp[root->val]++;
        solve(root->left,mp,sum);
        solve(root->right,mp,sum);
        mp[root->val]--;
    }
    int pathSum(TreeNode* root, int sum) {
        func(root,NULL);
        unordered_map<int,int> mp;
        mp[0]++;
        solve(root,mp,sum);
        return total;
    }
};








