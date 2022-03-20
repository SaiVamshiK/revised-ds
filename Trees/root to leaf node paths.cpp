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
    vector<string> func(TreeNode *root)
    {
        if(root==NULL)
        {
            vector<string> ans;
            return ans;
        }
        vector<string> ans1=func(root->left);
        vector<string> ans2=func(root->right);
        vector<string> fin;
        int data=root->val;
        if(ans1.size()==0&&(ans2.size()==0))
        {
            string h;
            h+=to_string(data);
            fin.push_back(h);
            return fin;
        }
        for(int i=0;i<(ans1.size());i++)
        {
            string t;
            t+=to_string(data);
            t.push_back('-');
            t.push_back('>');
            for(int j=0;j<(ans1[i].size());j++)
            {
                t.push_back(ans1[i][j]);
            }
            fin.push_back(t);
        }
        for(int i=0;i<(ans2.size());i++)
        {
            string t;
            t+=to_string(data);
            t.push_back('-');
            t.push_back('>');
            for(int j=0;j<(ans2[i].size());j++)
            {
                t.push_back(ans2[i][j]);
            }
            fin.push_back(t);
        }
        return fin;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans=func(root);
        return ans;
    }
};
