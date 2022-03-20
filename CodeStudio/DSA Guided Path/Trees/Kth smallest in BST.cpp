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

void func(TreeNode<int> *root,int &k,int &ans)
{
    if(root==NULL||(k==-1))
    {
        return ;
    }
    func(root->left,k,ans);
    k--;
    if(k==0)
    {
        k=-1;
        ans=(root->data);
    }
    func(root->right,k,ans);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	int ans;
    func(root,k,ans);
    return ans;
}



