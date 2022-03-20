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
            Node *t=q.front();
            q.pop();
            if(i==sz)
            {
                ans.push_back(t->data);
            }
            if(t->left)
            {
                q.push(t->left);
            }
            if(t->right)
            {
                q.push(t->right);
            }
            
        }
    }
}
vector<int> rightView(Node *root)
{
    vector<int> ans;
    func(root,ans);
    return ans;
}

