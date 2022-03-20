
Given two binary trees T and S, check whether tree S has exactly the same structure and node values with a subtree of T, i.e., check if tree S is a subtree of the tree T.
A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T. The subtree corresponding to the root node is the entire tree; the subtree corresponding to any other node is called a proper subtree.

/***************************************************
  Following is the TreeNode Structure

template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

*****************************************************/
#include<bits/stdc++.h>
using namespace std;

string findStr(TreeNode<int> *root)
{
    if(!root)
    {
        return "N";
    }
    string left=findStr(root->left);
    string right=findStr(root->right);
    return to_string(root->val)+"."+left+"."+right;
}

string func(TreeNode<int> *root,string &s,bool &done)
{
    if(!root)
    {
        return "N";
    }
    string left=func(root->left,s,done);
    string right=func(root->right,s,done);
    string cur=to_string(root->val)+"."+left+"."+right;
    if(cur==s)
    {
        done=true;
    }
    return cur;
}

bool isSubtree(TreeNode<int> *T, TreeNode<int> *S)
{
	string str=findStr(S);
    bool done=false;
    func(T,str,done);
    return done;
}
