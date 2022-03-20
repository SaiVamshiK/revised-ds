
Problem Statement
In a binary tree, a special node is a node that is the only child of its parent. The root of the tree is not special because it does not have a parent node. Node ‘1’ is always the root of the binary tree. Return an array/list containing the values of all special nodes in the tree.

/************************************************************

    Following is the TreeNode class structure.
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

bool isLeaf(TreeNode<int> *root)
{
    if((!root->left)&&(!root->right))
    {
        return true;
    }
    return false;
}

bool func(TreeNode<int> *root,vector<int> &ans)
{
    if(!root)
    {
        return false;
    }
    if(isLeaf(root))
    {
        return true;
    }
    bool left=func(root->left,ans);
    bool right=func(root->right,ans);
    if(left&&(!right))
    {
        ans.push_back(root->left->val);
        return true;
    }else if((!left)&&(right))
    {
        ans.push_back(root->right->val);
        return true;
    }else{
        return true;
    }
}

vector<int> findSpecialNodes(TreeNode<int> *root) {
	vector<int> ans;
    func(root,ans);
    return ans;
}




