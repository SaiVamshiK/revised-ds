/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preOrder(TreeNode *root,TreeNode *parent,unordered_map<TreeNode*,
                  TreeNode*> &nodeToParent,unordered_map<TreeNode*,bool> &visited){
        if(!root){
            return ;
        }
        visited[root]=false;
        nodeToParent.insert({root,parent});
        preOrder(root->left,root,nodeToParent,visited);
        preOrder(root->right,root,nodeToParent,visited);
    }
    vector<int> bfsTraversal(TreeNode *root,int k,
                        unordered_map<TreeNode*,TreeNode*> nodeToParent,unordered_map<TreeNode*,bool> visited){
        
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        visited[root] = true;
        int level = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode *curNode = q.front();
                q.pop();
                if(level ==  k){
                    ans.push_back(curNode->val);
                }
                if(curNode->left&&(!visited[curNode->left])){
                    q.push(curNode->left);
                    visited[curNode->left] = true;
                }
                if(curNode->right&&(!visited[curNode->right])){
                    q.push(curNode->right);
                    visited[curNode->right] = true;
                }
                if(nodeToParent[curNode]&&(!visited[nodeToParent[curNode]])){
                    q.push(nodeToParent[curNode]);
                    visited[nodeToParent[curNode]] = true;
                }
            }
            if(level == k){
                break;
            }
            level++;
        }
        return ans;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        unordered_map<TreeNode*,bool> visited;
        unordered_map<TreeNode*,TreeNode*> nodeToParent;
        preOrder(root,nullptr,nodeToParent,visited);
        return bfsTraversal(target,k,nodeToParent,visited);
    }
};
