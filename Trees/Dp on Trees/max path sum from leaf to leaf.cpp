
int func(Node *root,int &ans)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=func(root->left,ans);
    int r=func(root->right,ans);
    if(root->left&&root->right)
    {
        ans=max(ans,root->data+l+r);  
        return max(l,r)+root->data;
    }
    if(root->left)
    {
        return l+root->data;
    }
    if(root->right)
    {
        return r+root->data;
    }
    return root->data;
}
int maxPathSum(Node* root)
{ 
    int ans=INT_MIN;
    func(root,ans);
    return ans;
}

