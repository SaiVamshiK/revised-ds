/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
#include<bits/stdc++.h>
using namespace std;
BinaryTreeNode<int>* findInSucc(BinaryTreeNode<int>* root)
{
    BinaryTreeNode<int>* tempPointer=root->right;
    while(tempPointer->left)
    {
        tempPointer=tempPointer->left;
    }
    return tempPointer;
}

bool isLeaf(BinaryTreeNode<int>* root)
{
    if((!root->left)&&(!root->right))
    {
        return true;
    }
    return false;
}

BinaryTreeNode<int>* deleteInBST(BinaryTreeNode<int>* root,int key)
{
    if(root==NULL)
    {
        return root;
    }
    int curValue=(root->data);
    if(key<curValue)
    {
        root->left=deleteInBST(root->left,key);
        return root;
    }else if(key>curValue)
    {
        root->right=deleteInBST(root->right,key);
        return root;
    }else{
        if(isLeaf(root))
        {
            free(root);
            return NULL;
        }else{
            if((root->left)&&(root->right))
            {
                // 2 childs
                BinaryTreeNode<int>* inSucc=findInSucc(root);
                swap(root->data,inSucc->data);
                root->right=deleteInBST(root->right,inSucc->data);
                return root;
            }else if(root->left)
            {
                // left child exists
                BinaryTreeNode<int>* tempPointer=(root->left);
                free(root);
                return tempPointer;
            }else{
                // right child exists
                BinaryTreeNode<int>* tempPointer=(root->right);
                free(root);
                return tempPointer;
            }
        }
    }
}

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key){
    return deleteInBST(root,key);
}



