void serialize(Node *root,vector<int> &ans)
{
    if(root==NULL)
    {
        ans.push_back(-1);
        return ;
    }
    ans.push_back(root->data);
    serialize(root->left,ans);
    serialize(root->right,ans);
}



/*this function deserializes
 the serialized vector A*/
Node* func(vector<int> &ans,int &idx,int n)
{
    if(ans[idx]==-1)
    {
        return NULL;
    }
    if(idx==n)
    {
        return NULL;
    }
    Node *root=new Node(ans[idx]);
    idx++;
    root->left=func(ans,idx,n);
    idx++;
    root->right=func(ans,idx,n);
    return root;
}
Node * deSerialize(vector<int> &ans)
{
    int i;
    i=0;
    return func(ans,i,ans.size());
}


