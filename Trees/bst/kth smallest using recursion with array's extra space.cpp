// Return the Kth smallest element in the given BST 
void func(Node *root,int &ans,int &k)
{
    if(root==NULL)
    {
        return ;
    }
    func(root->left,ans,k);
    k--;
    if(k==0)
    {
        ans=root->data;
        return ;
    }
    func(root->right,ans,k);
}
int KthSmallestElement(Node *root, int k)
{
    int ans=-1;
    func(root,ans,k);
    return ans;
}

