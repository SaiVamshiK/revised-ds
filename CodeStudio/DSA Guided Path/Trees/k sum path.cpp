
Kevin has written some integers on a paper. He then selects some integers and draws a line between them. Fortunately, his diagram represents a binary tree. Today, his friend challenged him to find the paths that start from root and end at the leaf in his diagram whose sum is exactly equal to the number ‘K’. But, Kevin has another important piece of work and so, he appoints you to do his task.
All you have to do is to find the paths in his diagram whose sum is exactly equal to the number ‘K’.

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

bool isLeaf(TreeNode<int> *root)
{
	if((!root->left)&&(!root->right))
    {
        return true;
    }
    return false;
}

void func(TreeNode<int> *root,vector<int> &op,
         int sum,vector<vector<int>> &ans,int k)
{
    if(!root)
    {
        return ;
    }
    if(isLeaf(root))
    {
        if(sum==k)
        {
            ans.push_back(op);
        }
        return ;
    }
    if(root->left)
    {
        op.push_back(root->left->data);
        func(root->left,op,sum+(root->left->data),ans,k);
        op.pop_back();
    }
    if(root->right)
    {
        op.push_back(root->right->data);
        func(root->right,op,sum+(root->right->data),ans,k);
        op.pop_back();
    }
}

vector<vector<int>> KSumPaths(TreeNode<int> *root, int k)
{
    vector<vector<int>> ans;
    vector<int> op;
    if(!root)
    {
        return ans;
    }
    op.push_back(root->data);
    func(root,op,root->data,ans,k);
    return ans;
}



