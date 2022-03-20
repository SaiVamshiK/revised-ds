/**
Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* func(vector<int> &a,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=-1,ans=INT_MIN;
    for(int i=start;i<=end;i++)
    {
        if(ans<(a[i]))
        {
            ans=a[i];
            mid=i;
        }
    }
    TreeNode *root=new TreeNode(a[mid]);
    root->left=func(a,start,mid-1);
    root->right=func(a,mid+1,end);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &a) {
    int n=a.size();
    return func(a,0,n-1);
}

