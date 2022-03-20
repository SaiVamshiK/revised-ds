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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }        
        stack<TreeNode* > current,next;
        current.push(root);
        bool c=false;
        while(!current.empty())
        {
            vector<int> qwe;
            if(!c)
            {
                while(!current.empty())
                {
                    TreeNode *temp=current.top();
                    current.pop();
                    qwe.push_back(temp->val);
                    if(temp->left)
                    {
                        next.push(temp->left);
                    }
                    if(temp->right)
                    {
                        next.push(temp->right);
                    }
                }
                swap(current,next);
                c=!c;
            }else{
                while(!current.empty())
                {
                    TreeNode *temp=current.top();
                    current.pop();
                    qwe.push_back(temp->val);
                    if(temp->right)
                    {
                        next.push(temp->right);
                    }
                    if(temp->left)
                    {
                        next.push(temp->left);
                    }
                }
                swap(current,next);
                c=!c;
            }
            ans.push_back(qwe);
        }
        return ans;
    }
};









