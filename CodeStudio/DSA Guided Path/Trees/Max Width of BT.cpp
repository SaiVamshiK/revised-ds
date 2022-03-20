Problem Statement
You have been given a Binary Tree of integers. You are supposed to return the maximum width of the given Binary Tree. 
The maximum width of the tree is the maximum width among all the levels of the given tree.
The width of one level is defined as the length between the leftmost and the rightmost, non-null nodes in the level, where 
the null nodes in between the leftmost and rightmost are excluded into length calculation.


/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
using namespace std;
int getMaxWidth(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    int maxWidth=INT_MIN;
    while(!q.empty())
    {
		int sz=q.size();
        maxWidth=max(maxWidth,sz);
        for(int i=1;i<=sz;i++)
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
    return maxWidth;
}



















