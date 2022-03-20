
Problem Statement
You have been given a binary tree, you are supposed to return the root values of all the duplicate subtrees. For each duplicate subtree, you only need to return the root value of any one of them.
Two subtrees are duplicate if and only if they have the same structure with the same node values.


/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>
using namespace std;
string findST(TreeNode<int> *root,
              	unordered_map<string,int> &mp,vector<int> &ans)
{
    if(!root)
    {
        return "N";
    }
    int cur=(root->data);
    string left=findST(root->left,mp,ans);
    string right=findST(root->right,mp,ans);
    string curST=to_string(cur)+"."+left+"."+right;
    if(mp.find(curST)!=mp.end())
    {
        if(mp[curST]==1)
        {
            ans.push_back(cur);
        }
    }
    mp[curST]++;
    return curST;
}

vector<int> duplicateSubtrees(TreeNode<int> *root)
{
    unordered_map<string,int> mp;
    vector<int> ans;
    findST(root,mp,ans);
    if(ans.size()==0)
    {
        ans.push_back(-1);
    }
    return ans;
}




