/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isLeaf(TreeNode *a)
{
    if((!a->left)&&(!a->right))
    {
        return true;
    }
    return false;
}
void func(TreeNode *root,int &k,int &ans)
{
    if(root==NULL)
    {
        return ;
    }
    if(isLeaf(root))
    {
        k--;
        if(k==0)
        {
            ans=root->val;
        }
        return ;
    }
    func(root->left,k,ans);
    k--;
    if(k==0)
    {
        ans=root->val;
        return ;
    }
    func(root->right,k,ans);
}
int Solution::kthsmallest(TreeNode* root, int k) {
    int ans=INT_MIN;
    func(root,k,ans);
    return ans;
}

