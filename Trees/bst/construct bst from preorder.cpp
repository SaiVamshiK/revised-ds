/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* func(vector<int>& a,int l,int r)
    {
        if(l>r)
        {
            return NULL;
        }
        TreeNode *root=new TreeNode(a[l]);
        int x;
        for(int i=l+1;i<=r;i++)
        {
            if(a[i]>a[l])
            {
                x=i;
                break;
            }
        }
        root->left=func(a,l+1,x-1);
        root->right=func(a,x,r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return func(preorder,0,preorder.size()-1);
    }
};









