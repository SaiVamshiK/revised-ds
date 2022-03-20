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

BinaryTreeNode<int>* func(BinaryTreeNode<int> *root)
{
    if(!root)
    {
        return NULL;
    }
    if(isLeaf(root))
    {
        return root;
    }
    BinaryTreeNode<int> *left=func(root->left);
    BinaryTreeNode<int> *right=func(root->right);
    root->left=right;
    root->right=left;
    return root;
}

void mirrorTree(BinaryTreeNode<int> *root) {
    root=func(root);
}



