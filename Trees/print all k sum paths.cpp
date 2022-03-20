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
    int ans=0;
    vector<vector<int >> vec;
    void explore(TreeNode *root,int sum,int cur,vector<int > temp)
    {
        if(root==NULL) return ;
        cur=cur+root->val;
        temp.push_back(root->val);
        if(cur==sum)
        {
            vec.push_back(temp);
            ans++;
        }
        explore(root->left,sum,cur,temp);
        explore(root->right,sum,cur,temp);
    }
    void func(TreeNode *root,int sum)
    {
        if(root==NULL) return;
        vector<int > temp;
        explore(root,sum,0,temp);
        func(root->left,sum);
        func(root->right,sum);
    }
    int pathSum(TreeNode* root, int sum) {
        func(root,sum);
        for(int i=0;i<(vec.size());i++)
        {
            for(int j=0;j<(vec[i].size());j++)
            {
                cout<<vec[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<"Done"<<endl;
        return ans;
    }
};
