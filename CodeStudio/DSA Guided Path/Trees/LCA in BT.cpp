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


TreeNode<int>* findLCA(TreeNode<int> *root,int x,int y)
{
    if(!root)
    {
        return root;
    }
    int cur=(root->data);
    if(x==cur||(y==cur))
    {
        return root;
    }
    TreeNode<int> *left=findLCA(root->left,x,y);
    TreeNode<int> *right=findLCA(root->right,x,y);
    if(left&&right)
    {
        return root;
    }else if(left)
    {
        return left;
    }
    return right;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    TreeNode<int> *val=findLCA(root,x,y);
    return (val->data);
}




