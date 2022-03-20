
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

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
    string func(TreeNode *root,unordered_map<string,int> &mp,vector<TreeNode*> &vec)
    {
        if(root==NULL)
        {
            return "n";
        }
        string left=func(root->left,mp,vec);
        string right=func(root->right,mp,vec);
        int d=root->val;
        string ans=to_string(d)+"."+left+"."+right;
        mp[ans]++;
        if(mp[ans]==2)
        {
            vec.push_back(root);
        }
        return ans;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*> vec;
        func(root,mp,vec);   
        return vec;
    }
};






