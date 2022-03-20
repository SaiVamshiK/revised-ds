int func(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=func(root->left);
    int right=func(root->right);
    int cur=root->data;
    root->data=left+right;
    return cur+root->data;
}
void toSumTree(Node *node)
{
    func(node);
}

