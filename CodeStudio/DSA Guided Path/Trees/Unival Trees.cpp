You are given a binary tree. Return the count of unival sub-trees in the given binary tree. In unival trees, all the nodes, below the root node, have the same value as the data of the root.
For example: for the binary tree, given in the following diagram, the number of unival trees is 5.
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
typedef pair<bool,int> pi;
bool isLeaf(BinaryTreeNode<int> *root)
{
    if((!root->left)&&(!root->right))
    {
        return true;
    }
    return false;
}
pi func(BinaryTreeNode<int> *root,int &count)
{
    if(root==NULL)
    {
        return {true,-1};
    }
    if(isLeaf(root))
    {
        count++;
        int curValue=root->data;
        return {true,curValue};
    }
    pi left=func(root->left,count);
    pi right=func(root->right,count);
    int curValue=(root->data);
    if(left.first&&(right.first))
    {
		if((left.second==curValue||(left.second==-1))
           &&(right.second==curValue||(right.second==-1)))
        {
            count++;
            return {true,curValue};
        }else{
        	return {false,-1};    
        }
    }else{
        return {false,-1};
    }
}
int countUnivalTrees(BinaryTreeNode<int> *root)
{
    int count=0;
    func(root,count);
    return count;
}















