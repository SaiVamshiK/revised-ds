Problem Statement
You have been given a sorted array of length ‘N’. You need to construct a balanced binary search tree from the array. If there can be more than one possible tree, then you can return any.

/************************************************************

    Following is the TreeNode class structure

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

TreeNode<int>* func(vector<int> &a,int low,int high)
{
    if(low>high)
    {
        return NULL;
    }
    int mid=low+((high-low)/2);
    TreeNode<int> *root=new TreeNode<int>(a[mid]);
    root->left=func(a,low,mid-1);
    root->right=func(a,mid+1,high);
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return func(arr,0,n-1);
}



