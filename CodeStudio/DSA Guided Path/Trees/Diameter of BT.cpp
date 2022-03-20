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

int findDiameter(TreeNode<int> *root,int &diameter)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=findDiameter(root->left,diameter);
    int right=findDiameter(root->right,diameter);
    diameter=max(diameter,left+right);
    return 1+max(left,right);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int diameter=0;
    findDiameter(root,diameter);
    return diameter;
}





