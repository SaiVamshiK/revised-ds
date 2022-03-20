void func(Node *root,vector<int> &ans)
{
    if(root==NULL)
    {
        return ;
    }
    queue<Node* > q;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=1;i<=sz;i++)
        {
            Node *temp=q.front();
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            if(i==1)
            {
                ans.push_back(temp->data);
            }
        }
    }
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    func(root,ans);
    return ans;
}


