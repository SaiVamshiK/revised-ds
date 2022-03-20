/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ht(TreeNode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(ht(root->left),ht(root->right));
}
bool func(TreeNode *root)
{
    if(root==NULL)
    {
        return true;
    }
    bool a1=func(root->left);
    bool a2=func(root->right);
    if(!(a1&&a2))
    {
        return false;
    }
    int h1=ht(root->left),h2=ht(root->right);
    if(abs(h1-h2)<=1)
    {
        return true;
    }else{
        return false;
    }
}
int Solution::isBalanced(TreeNode* A) {
    if(func(A))
    {
        return 1;
    }
    return 0;
}

