
Problem Statement
You have been given a Binary Tree of integers, find the minimum depth of this Binary Tree. 
The minimum depth of a Binary Tree is the number of nodes along the shortest path from the root node down to the nearest leaf node.


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
#include<bits/stdc++.h>
using namespace std;
bool isLeaf(TreeNode<int>* root)
{
    if((!root->left)&&(!root->right))
    {
        return true;
    }
    return false;
}

int func(TreeNode<int>* root)
{
    if(isLeaf(root))
    {
        return 1;
    }
    int left,right;
    if((root->left)&&(root->right))
    {
        left=func(root->left);
        right=func(root->right);
        return min(left,right)+1;
    }else if(root->left)
    {
        left=func(root->left);
        return 1+left;
    }else
    {
        right=func(root->right);
        return 1+right;
    }
    
}

int minDepth(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return func(root);
}


