void func(Node *root,int &ans,int &k)
{
    if(root==NULL)
    {
        return ;
    }
    func(root->right,ans,k);
    k--;
    if(k==0)
    {
        ans=root->data;
        return ;
    }
    func(root->left,ans,k);
}
int kthLargest(Node *root, int k)
{
    int ans=-1;
    func(root,ans,k);
    return ans;
}
