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
    void func(TreeNode *root,int sum,vector<int> vec,vector<vector<int>> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        if((root->left==NULL)&&(root->right==NULL)&&(sum==root->val))
        {
            vec.push_back(root->val);
            ans.push_back(vec);
            return ;
        }
        vec.push_back(root->val);
        func(root->left,sum-root->val,vec,ans);
        func(root->right,sum-root->val,vec,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> vec;
        if(root==NULL)
        {
            return ans;
        }
        func(root,sum,vec,ans);
        return ans;
    }
};
