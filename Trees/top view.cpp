void topView(struct Node *root)
{
    queue<pair<Node*,int>> q;
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node*,int> temp=q.front();
        q.pop();
        Node *w=temp.first;
        int hd=temp.second;
        if(mp.count(hd)==0)
        {
            mp[hd]=w->data;
        }
        if(w->left)
        {
            q.push({w->left,hd-1});
        }
        if(w->right)
        {
            q.push({w->right,hd+1});
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<(it->second)<<' ';
    }
}

