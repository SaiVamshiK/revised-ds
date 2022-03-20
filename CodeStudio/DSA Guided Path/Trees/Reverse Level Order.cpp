
Problem Statement
You have been given a Binary Tree of integers. You are supposed to return the reverse of the level order traversal.

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> reverseLevelOrder(TreeNode<int> *root){
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    vector<vector<int>> v;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        vector<int> temp;
        for(int i=1;i<=sz;i++)
        {
			TreeNode<int> *cur=q.front();
            temp.push_back(cur->val);
            q.pop();
            if(cur->right)
            {
                q.push(cur->right);
            }
            if(cur->left)
            {
                q.push(cur->left);
            }
        }
        v.push_back(temp);
    }
    int len=v.size();
    for(int i=len-1;i>=0;i--)
    {
		for(int j=0;j<(v[i].size());j++)
        {
            ans.push_back(v[i][j]);
        }
    }
    return ans;
}










