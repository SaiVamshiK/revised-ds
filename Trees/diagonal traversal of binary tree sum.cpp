/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/
void func(Node *root,map<int,int > &mp)
{
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node*,int> cur=q.front();
        q.pop();
        Node *cur_node=cur.first;
        int cur_dia=cur.second;
        mp[cur_dia]+=cur_node->data;
        if(cur_node->left)
        {
            q.push({cur_node->left,cur_dia+1});
        }
        if(cur_node->right)
        {
            q.push({cur_node->right,cur_dia});
        }
    }
}
vector <int> diagonalSum(Node* root) {
    vector <int> ans;
    map<int,int > mp;
    func(root,mp);
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}


