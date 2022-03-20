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
    void func(TreeNode *root,vector<int> &ans)
    {
        TreeNode *cur=root;
        while(cur!=NULL)
        {
            if(cur->left==NULL)
            {
                ans.push_back(cur->val);
                cur=cur->right;
            }else{
                TreeNode *left_node=cur->left;
                TreeNode *q=left_node;
                while(left_node->right)
                {
                    left_node=left_node->right;
                }
                left_node->right=cur;
                cur->left=NULL;
                cur=q;   
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        func(root,ans);
        return ans;
    }
};

