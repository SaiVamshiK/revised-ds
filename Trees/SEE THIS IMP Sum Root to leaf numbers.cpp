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
 
 You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers.

A leaf node is a node with no children.

class Solution {
public:
    bool isLeaf(TreeNode *root)
    {
        if(!root->left&&(!root->right))
        {
            return true;
        }
        return false;
    }
    vector<pair<int,int>> func(TreeNode *root)
    {
        if(root==NULL)
        {
            vector<pair<int,int>> ans;
            ans.push_back({INT_MIN,INT_MIN});
            return ans;
        }
        if(isLeaf(root))
        {
            vector<pair<int,int>> ans;
            ans.push_back({root->val,1});
            return ans;
        }
        int current=root->val;
        vector<pair<int,int>> ans;
        vector<pair<int,int>> left=func(root->left);
        if(left.size()==1&&((left[0].first==INT_MIN)&&(left[0].second==INT_MIN)))
        {

        }else{
            for(int i=0;i<(left.size());i++)
            {
                int val=left[i].first,power=left[i].second;
                int result;
                int x=pow(10,power);
                result=((x*current));
                result=result+val;
                ans.push_back({result,power+1});
            }
        }

        vector<pair<int,int>> right=func(root->right);
        if(right.size()==1&&((right[0].first==INT_MIN)&&(right[0].second==INT_MIN)))
        {

        }else{
            for(int i=0;i<(right.size());i++)
            {
                int val=right[i].first,power=right[i].second;
                int result;
                int x=pow(10,power);
                result=((x*current));
                result=result+val;
                ans.push_back({result,power+1});
            }   
        }

        return ans;
    }
    int sumNumbers(TreeNode* root) {
        vector<pair<int,int>> ans=func(root);
        int sum=0;
        for(int i=0;i<(ans.size());i++)
        {
            sum+=(ans[i].first);
        }
        return sum;
    }
};
