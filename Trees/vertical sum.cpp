/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/

Input:
       1
    /   \
  2      3
 / \    / \
4   5  6   7
Output: 
Explanation:
The tree has 5 vertical lines
Vertical-Line-1 has only one node
4 => vertical sum is 4
Vertical-Line-2: has only one node
2=> vertical sum is 2
Vertical-Line-3: has three nodes:
1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3
=> vertical sum is 3
Vertical-Line-5: has only one node 7
=> vertical sum is 7

vector<int> verticalSum(Node *root) {
    queue<pair<Node*,int>> q;
    q.push({root,0});
    map<int,int> mp;
    // hd elem
    while(!q.empty())
    {
        pair<Node*,int> temp=q.front();
        q.pop();
        Node *cur=temp.first;
        int hd=temp.second;
        mp[hd]+=(cur->data);
        if(cur->left)
        {
            q.push({cur->left,hd-1});
        }
        if(cur->right)
        {
            q.push({cur->right,hd+1});
        }
    }
    vector<int> ans;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}

