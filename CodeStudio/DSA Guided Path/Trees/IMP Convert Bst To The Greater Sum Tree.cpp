
Problem Statement
You have been given a Binary Search Tree of integers. You are supposed to convert it to a greater sum tree such that the value of every node in the given BST is replaced with the sum of the values of all the nodes which are greater than the value of the current node in the tree.
A Binary Search Tree is a tree, whose internal nodes each store a value greater than all the values in the node's left subtree and less than those in its right subtree.
Note :
You need to modify the given tree only. You are not allowed to create a new tree.

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

void preOrder(TreeNode<int> *root,int &sum)
{
    if(root==NULL)
    {
        return ;
    }
    preOrder(root->right,sum);
    int cur=(root->val);
    root->val=sum;
    sum=sum+cur;
    preOrder(root->left,sum);
}

TreeNode<int> *convertBstToGreaterSum(TreeNode<int> *root)
{
    int sum=0;
    preOrder(root,sum);
    return root;
}




