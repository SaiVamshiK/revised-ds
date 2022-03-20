/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root, int B) {
    queue<pair<TreeNode*,TreeNode*>> q;
    q.push({root,NULL});
    vector<int> ans;
    while(!q.empty())
    {
        int sz=q.size();
        // check
        vector<pair<TreeNode*,TreeNode*>> vec;
        bool done=false;
        TreeNode *main_parent=NULL;
        for(int i=1;i<=sz;i++)
        {
            pair<TreeNode*,TreeNode*> front=q.front();
            q.pop();
            vec.push_back(front);
            if(front.first->val==(B))
            {
                main_parent=front.second;
                done=true;
            }
            if(front.first->left)
            {
                q.push({front.first->left,front.first});
            }
            if(front.first->right)
            {
                q.push({front.first->right,front.first});
            }
        }
        if(done)
        {
            for(int i=0;i<(vec.size());i++)
            {
                pair<TreeNode*,TreeNode*> temp=vec[i];
                if(temp.second!=main_parent)
                {
                    ans.push_back(temp.first->val);
                }
            }
            return ans;
        }
    }
    return ans;
}

