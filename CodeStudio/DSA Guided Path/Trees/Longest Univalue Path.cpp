Problem Statement
You are given a binary tree, the task is to find out the length of the longest path which contains nodes with the exact same value. 
It is not necessary for the path to pass through the root of the binary tree.
Between two nodes, the length of the path can be defined as the number of edges contained between them.

typedef pair<int,int> pi;
bool isLeaf(BinaryTreeNode<int> *root)
{
    if((!root->left)&&(!root->right))
    {
        return true;
    }
    return false;
}
// {val,len}
pi func(BinaryTreeNode<int> *root,int &len)
{
    if(isLeaf(root))
    {
        return {root->data,1};
    }
    if(root->left&&(root->right))
    {
     	pi left=func(root->left,len);
        pi right=func(root->right,len);
        int curVal=(root->data);
        int leftVal=left.first,rightVal=right.first;
        int leftLen=left.second,rightLen=right.second;   
        if(leftVal==curVal&&(rightVal==curVal))
        {
            len=max(len,1+leftLen+rightLen);
            return {curVal,1+max(leftLen,rightLen)};
        }else if(leftVal==curVal)
        {
            len=max(len,1+leftLen);
            return {curVal,1+leftLen};
        }else if(rightVal==curVal){
            len=max(len,1+rightLen);
            return {curVal,1+rightLen};
        }else{
            return {curVal,1};
        }
    }else if(root->left)
    {
        pi left=func(root->left,len);
        int curVal=(root->data);
        int leftVal=left.first,leftLen=left.second;
        if(curVal==leftVal)
        {
            len=max(len,1+leftLen);
            return {curVal,1+leftLen};
        }else{
            return {curVal,1};
        }
    }else{
        pi right=func(root->right,len);
        int curVal=(root->data);
        int rightVal=right.first,rightLen=right.second;
        if(curVal==rightVal)
        {
            len=max(len,1+rightLen);
            return {curVal,1+rightLen};
        }else{
            return {curVal,1};
        }
    }
}

int longestUnivaluePath(BinaryTreeNode<int> *root) {
    int len=1;
    func(root,len);
    return len-1;
}
