Problem Statement
Given a binary tree. You need to check if it is a height-balanced binary tree.
Height of a tree is the maximum number of nodes in a path from the node to the leaf node.
An empty tree is a height-balanced tree. A non-empty binary tree is a height-balanced binary tree if
1. The left subtree of a binary tree is already the height-balanced tree.
2. The right subtree of a binary tree is also the height-balanced tree.
3. The difference between heights of left subtree and right subtree must not more than ‘1’.

/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool isLeaf(BinaryTreeNode<int>* root)
{
    if((!root->left)&&(!root->right))
    {
        return true;
    }
    return false;
}

int findIfBalanced(BinaryTreeNode<int>* root,bool &isBalanced)
{
    if(root==NULL)
    {
        return 0;
    }
    if(isLeaf(root))
    {
        return 1;
    }
    int left=findIfBalanced(root->left,isBalanced);
    if(!isBalanced)
    {
        return -1;
    }
    int right=findIfBalanced(root->right,isBalanced);
    if(!isBalanced)
    {
        return -1;
    }
    if((abs(left-right))>1)
    {
        isBalanced=false;
    }
    if(!isBalanced)
    {
        return -1;
    }
    return max(left,right)+1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    bool isBalanced=true;
    findIfBalanced(root,isBalanced);
    return isBalanced;
}




