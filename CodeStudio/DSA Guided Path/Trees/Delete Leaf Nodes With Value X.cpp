
Problem Statement
You are given a binary tree, in which the data present in the nodes are integers. You are also given an integer X.
Your task is to delete all the leaf nodes with value X. In the process, if the newly formed leaves also have value X, you have to delete them too.
For Example:

For the given binary tree, and X = 3:

/************************************************************
  
    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

    
************************************************************/

bool isLeaf(BinaryTreeNode<int>* root)
{
    if((!root->left)&&(!root->right))
    {
        return true;
    }
    return false;
}

bool func(BinaryTreeNode<int>* root,int &x)
{
    if(root==NULL)
    {
        return true;
    }
    if(isLeaf(root))
    {
        if((root->data)==x)
        {
            return true;
        }
        return false;
    }
    bool left=func(root->left,x);
    bool right=func(root->right,x);
    if(left)
    {
        root->left=NULL;
    }
    if(right)
    {
        root->right=NULL;
    }
    if((root->data)==x)
    {
        if(left&&(right))
        {
            return true;
        }
        return false;
    }else{
        return false;
    }
}

BinaryTreeNode<int>* deleteLeafNodes(BinaryTreeNode<int> *root, int x)
{
	bool ans=func(root,x);
    if(ans)
    {
        return NULL;
    }
    return root;
}











