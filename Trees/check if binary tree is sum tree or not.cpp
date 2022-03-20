pair<bool,int> func(Node *root)
{
    if(root==NULL)
    {
        return {true,0};
    }
    pair<bool,int> left=func(root->left);
    pair<bool,int> right=func(root->right);
    if(left.first&&right.first)
    {
        if(root->left==NULL&&(root->right==NULL))
        {
            return {true,root->data};
        }
        if(root->data==left.second+right.second)
        {
            return {true,root->data+left.second+right.second};
        }
        return {false,0};
    }
    return {false,0};
}
bool isSumTree(Node* root)
{
     pair<bool,int> ans=func(root);
     return ans.first;
}
