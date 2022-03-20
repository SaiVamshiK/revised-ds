/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void preOrder(TreeNode *root,map<int,vector<int>> &mp,int i)
{
    if(root)
    {
        mp[i].push_back(root->val);
        preOrder(root->left,mp,i+1);
        preOrder(root->right,mp,i);   
    }
}
vector<int> Solution::solve(TreeNode* root) {
    map<int,vector<int>> mp;
    preOrder(root,mp,0);
    vector<int> ans;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        vector<int> temp=(it->second);
        for(int i=0;i<(temp.size());i++)
        {
            ans.push_back(temp[i]);
        }
    }
    return ans;
}

