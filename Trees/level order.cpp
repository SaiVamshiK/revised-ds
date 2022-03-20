void levelorder(Node *root,vector<int> &ans)
{
    queue<Node* > q;
    q.push(root);
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
}
vector<int> levelOrder(Node* root)
{
    vector<int> ans;
    levelorder(root,ans);
    return ans;
}
