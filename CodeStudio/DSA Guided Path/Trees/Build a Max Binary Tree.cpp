
Problem Statement
You have been given an array/list ‘TREE’ having ‘N’ unique integers. You need to make a maximum binary tree recursively from ‘TREE’ using the following conditions:
1. Create a root of the maximum binary tree whose value is the maximum value present in the ‘TREE’.
2. Recursively build the left subtree on the subarray prefix to the left of the maximum value.
3. Recursively build the right subtree on the subarray suffix to the right of the maximum value.

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
#include<bits/stdc++.h>
using namespace std;
BinaryTreeNode<int>* func(vector<int> &a,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    if(start==end)
    {
        return new BinaryTreeNode<int>(a[start]);
    }
    int idx=-1;
    int maxVal=INT_MIN;
    for(int i=start;i<=end;i++)
    {
        if(maxVal<a[i])
        {
            maxVal=a[i];
            idx=i;
        }
    }
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(a[idx]);
    root->left=func(a,start,idx-1);
    root->right=func(a,idx+1,end);
    return root;
}

BinaryTreeNode<int> *constructMaximumBinaryTree(vector<int> &tree, int n) {
    return func(tree,0,n-1);
}
