
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/*You are required to complete below method */
int maxLevelSum(Node* root) {
    queue<Node* > q;
    q.push(root);
    int ans=INT_MIN;
    while(!q.empty())
    {
        int sz=q.size(),sum=0;
        for(int i=1;i<=sz;i++)
        {
            Node *temp=q.front();
            q.pop();
            sum+=(temp->data);
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        ans=max(ans,sum);
    }
    return ans;
}

