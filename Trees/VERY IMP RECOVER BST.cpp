Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

 Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::recoverTree(TreeNode* root) {
    TreeNode *cur=root;
    vector<int> ans;
    int prev=INT_MAX;
    vector<pair<int,int>> fin;
    while(cur)
    {
        if(cur->left)
        {
            TreeNode *temp=cur->left;
            while(temp->right&&(temp->right!=cur))
            {
                temp=temp->right;
            }
            if(temp->right==cur)
            {
                if((prev==INT_MAX)||((cur->val)>prev))
                {
                    prev=(cur->val);
                }else{
                    fin.push_back({prev,(cur->val)});
                    prev=(cur->val);
                }
                temp->right=NULL;
                cur=cur->right;
            }
            else{
                temp->right=cur;
                cur=cur->left;
            }
        }else{
            if((prev==INT_MAX)||((cur->val)>prev))
            {
                prev=(cur->val);
            }else{
                fin.push_back({prev,(cur->val)});
                prev=(cur->val);
            }
            cur=cur->right;
        }
    }
    if(fin.size()==1)
    {
        ans.push_back(fin[0].second);
        ans.push_back(fin[0].first);
        return ans;
    }
    ans.push_back(fin[1].second);
    ans.push_back(fin[0].first);
    return ans;
}


