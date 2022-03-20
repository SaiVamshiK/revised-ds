/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void func(TreeNode *root,int val,vector<int> ans,bool &counter,vector<int> &fin)
{
    if(root==NULL)
    {
        return ;
    }
    if(counter)
    {
        return ;
    }
    ans.push_back(root->val);
    if(root->val==val)
    {
        counter=true;
        fin=ans;
        return;
    }
    func(root->left,val,ans,counter,fin);
    func(root->right,val,ans,counter,fin);
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans,fin;
    bool counter=false;
    func(A,B,ans,counter,fin);
    return fin;
}

