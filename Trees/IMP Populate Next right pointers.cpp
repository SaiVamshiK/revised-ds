/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* root) {
    queue<TreeLinkNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=1;i<sz;i++)
        {
            TreeLinkNode *cur=q.front();
            q.pop();
            cur->next=q.front();
            if(cur->left)
            {
                q.push(cur->left);
            }
            if(cur->right)
            {
                q.push(cur->right);
            }
        }
        TreeLinkNode *cur=q.front();
        q.pop();
        if(cur->left)
        {
            q.push(cur->left);
        }
        if(cur->right)
        {
            q.push(cur->right);
        }
    }
}

