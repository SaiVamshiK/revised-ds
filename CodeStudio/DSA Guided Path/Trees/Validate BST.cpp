Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree) or not. If yes, return true, return false otherwise.
A binary search tree (BST) is a binary tree data structure which has the following properties.
• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.

struct Node{
  	bool isBst;
    int minVal;
    int maxVal;
};

bool isLeaf(BinaryTreeNode<int> *root)
{
    if((!root->left)&&(!root->right))
    {
        return true;
    }
    return false;
}

Node func(BinaryTreeNode<int> *root)
{
    if(isLeaf(root))
    {
        Node ans;
        ans.isBst=true;
        ans.minVal=(root->data);
        ans.maxVal=(root->data);
        return ans;
    }
    Node left,right;
    if((root->left)&&(root->right))
    {
        left=func(root->left);
        right=func(root->right);
        int cur=(root->data);
        if(left.isBst&&(right.isBst))
        {
            if((left.maxVal<=cur)&&(cur<=right.minVal))
            {
                Node ans;
                ans.isBst=true;
                ans.minVal=left.minVal;
                ans.maxVal=right.maxVal;
                return ans;
            }
        }
        Node ans;
        ans.isBst=false;
        ans.minVal=-1;
        ans.maxVal=-1;
        return ans;
    }else if(root->left)
    {
        left=func(root->left);
        int cur=(root->data);
        if(left.isBst)
        {
            if(left.maxVal<=cur)
            {
                Node ans;
                ans.isBst=true;
                ans.minVal=left.minVal;
                ans.maxVal=cur;
                return ans;
            }
        }
        Node ans;
        ans.isBst=false;
        ans.minVal=-1;
        ans.maxVal=-1;
        return ans;
    }else
    {
        right=func(root->right);
        int cur=(root->data);
        if(right.isBst)
        {
            if(cur<=right.minVal)
            {
                Node ans;
                ans.isBst=true;
                ans.minVal=cur;
                ans.maxVal=right.maxVal;
                return ans;
            }
        }
        Node ans;
        ans.isBst=false;
        ans.minVal=-1;
        ans.maxVal=-1;
        return ans;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    if(!root)
    {
        return true;
    }
    Node ans=func(root);
    return ans.isBst;
}

