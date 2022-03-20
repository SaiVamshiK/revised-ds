
/*You are required to complete this method*/
bool isLeaf(Node *root)
{
    if(root->left==NULL&&root->right==NULL) return true;
    return false;
}
bool check(Node *root)
{
    
    queue<Node*> q;
    q.push(root);
    map<int,int> mp;
    int level=1;
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=1;i<=sz;i++)
        {
            Node *temp=q.front();
            q.pop();
            if(isLeaf(temp))
            {
                mp[level]=temp->data;   
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        level++;
    }
    return mp.size()==1;
}


