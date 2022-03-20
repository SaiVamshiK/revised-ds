Problem Statement
You have been given a Binary Tree where the value of each node is either 0 or 1. Your task is to return the same Binary Tree but all of its subtrees that don't contain a 1 have been removed.
Note :
A subtree of a node X is X, plus every node that is a descendant of X.
For Example :
Look at the below example to see a Binary Tree pruning.
Input: [1, 1, 1, 0, 1, 0, 1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1]

/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* root)
{
    if((!root->left)&&(!root->right))
    {
        return true;
    }
    return false;
}
bool func(TreeNode<int>* root)
{	
    if(root==NULL)
    {
        return true;
    }
  	if(isLeaf(root))
    {
        if(root->val==0)
        {
            return true;
        }
        return false;
    }
    bool left=func(root->left);
    bool right=func(root->right);
    if(left)
    {
        root->left=NULL;
    }
    if(right)
    {
        root->right=NULL;
    }
    if(root->val==0)
    {
        if(left&&right)
        {
            return true;
        }
        return false;
    }else{
        return false;
    }
}

TreeNode<int>* binaryTreePruning(TreeNode<int>* root)
{
    bool ans=func(root);
    if(ans)
    {
        return NULL;
    }
	return root;
}
















