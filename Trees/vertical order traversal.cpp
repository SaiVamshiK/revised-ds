vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    TreeNode *root=A;
    if(root==NULL)
    {
        vector<vector<int> > qwe;        
        return qwe;
    }
    queue<pair<TreeNode*,int>> q;
    map<int,vector<int>> mp;
    q.push({root,0});
    while(!q.empty())
    {
        auto temp=q.front();
        q.pop();
        TreeNode *qwe=temp.first;
        int hd=temp.second;
        mp[hd].push_back(qwe->val);
        if(qwe->left)
        {
            q.push({qwe->left,hd-1});
        }
        if(qwe->right)
        {
            q.push({qwe->right,hd+1});
        }
    }
    vector<vector<int> > ans;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        vector<int> temp=it->second;
        ans.push_back(temp);
    }
    return ans;
}

