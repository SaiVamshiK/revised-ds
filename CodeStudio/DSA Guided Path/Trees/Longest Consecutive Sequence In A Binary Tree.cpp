
Problem Statement
Given a binary tree, return the length of the longest path which has consecutive integers in increasing order from root to leaves. 
A path is defined as a sequence of nodes which share an edge between them.

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
typedef pair<int,int> pi;
bool isLeaf(BinaryTreeNode<int> *root)
{
    if((!root->left)&&(!root->right))
    {
        return true;
    }
    return false;
}
// {value,len}
pi func(BinaryTreeNode<int> *root,int &ans)
{
    if(isLeaf(root))
    {
        return {root->data,1};
    }
    if(root->left&&(root->right))
    {
 		pi left=func(root->left,ans);
        pi right=func(root->right,ans);
        int leftVal=left.first,leftFreq=left.second;
        int rightVal=right.first,rightFreq=right.second;
        int curVal=(root->data);
        if((curVal+1)==leftVal&&((curVal+1)==rightVal))
        {
            ans=max(ans,1+max(leftFreq,rightFreq));
            return {curVal,1+max(leftFreq,rightFreq)};
        }else if((curVal+1)==leftVal)
        {
            ans=max(ans,1+leftFreq);
            return {curVal,1+leftFreq};
        }else if((curVal+1)==rightVal)
        {
            ans=max(ans,1+rightFreq);
            return {curVal,1+rightFreq};
        }else{
            return {curVal,1};
        }
    }else if(root->left)
    {
        pi left=func(root->left,ans);
        int leftVal=left.first,leftFreq=left.second;
        int curVal=(root->data);
        if((curVal+1)==leftVal)
        {
            ans=max(ans,1+leftFreq);
            return {curVal,1+leftFreq};
        }else{
            return {curVal,1};
        }
    }else{
        pi right=func(root->right,ans);
        int rightVal=right.first,rightFreq=right.second;
        int curVal=(root->data);
        if((curVal+1)==rightVal)
        {
            ans=max(ans,1+rightFreq);
            return {curVal,1+rightFreq};
        }else{
            return {curVal,1};
        }
    }
}
int maxPath(BinaryTreeNode<int> *root) {
    int ans=1;
    func(root,ans);
    return ans;
}








