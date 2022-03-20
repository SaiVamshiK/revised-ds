
Problem Statement
You are given a binary tree. Your task is to check whether the given binary tree is a Complete Binary tree or not.
A Complete Binary tree is a binary tree whose every level, except possibly the last, is completely filled, and all nodes in the 
last level are placed at the left end.

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
      public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
using namespace std;
int findHt(TreeNode<int> *root)
{
    if(!root)
    {
        return 0;
    }
    int left=findHt(root->left);
    int right=findHt(root->right);
    return 1+max(left,right);
}

bool isLeaf(TreeNode<int> *root)
{
    if((!root->left)&&(!root->right))
    {
        return true;
    }
    return false;
}

bool func(TreeNode<int> *root,int &lastLevel)
{
    if(!root||(isLeaf(root)))
    {
        return true;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    int level=0;
    while(!q.empty())
    {
        int sz=q.size();
        int curNodes=sz;
        if(pow(2,level)!=curNodes)
        {
        	return false;
        }
        if(level==(lastLevel-1))
        {
            bool done=false;
         	int i=0;
            while(i<sz)
            {
                TreeNode<int> *cur=q.front();
                q.pop();
                i++;
                if(!cur->left)
                {
                    done=true;
                    if(cur->right)
                    {
                        return false;
                    }
                    break;
                }
                if(!cur->right){
                    done=true;
                    break;
                }
            }  
            if(done)
            {
				while(i<sz)
                {
                    TreeNode<int> *cur=q.front();
                    q.pop();
                    i++;
                    if(cur->left||(cur->right))
                    {
                        return false;
                    }
                }
            }
            return true;
        }else{
         	for(int i=0;i<sz;i++)
            {
                TreeNode<int> *cur=q.front();
                q.pop();
                if(cur->left)
                {
                    q.push(cur->left);
                }
                if(cur->right)
                {
                    q.push(cur->right);
                }
            }   
        }
        level++;
    }
}

int isCompleteBinaryTree(TreeNode<int> *root)
{
    int lastLevel=findHt(root)-1;
    return func(root,lastLevel);
}

