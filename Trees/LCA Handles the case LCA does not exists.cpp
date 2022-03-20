/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 ;
**/
TreeNode* func(TreeNode *root,int x,int y)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->val==x||(root->val==y))
    {
        return root;
    }
    TreeNode *left=func(root->left,x,y);
    TreeNode *right=func(root->right,x,y);
    if((left==NULL)&&(right==NULL))
    {
        return NULL;
    }
    if((left)&&(!right))
    {
        return left;
    }
    if((right)&&(!left))
    {
        return right;
    }
    return root;
}
void pre(TreeNode *root,bool &done1,bool &done2,int x,int y)
{
    if(root)
    {
        if(root->val==(x))
        {
            done1=true;
        }
        if(root->val==(y))
        {
            done2=true;
        }
        pre(root->left,done1,done2,x,y);
        if(done1&&(done2))
        {
            return ;
        }
        pre(root->right,done1,done2,x,y);
    }
}
int Solution::lca(TreeNode* A, int B, int C) {
    bool done1=false,done2=false;
    pre(A,done1,done2,B,C);
    if(done1&&done2)
    {
        TreeNode *ans=func(A,B,C);
        return ans->val;    
    }
    return -1;
}

