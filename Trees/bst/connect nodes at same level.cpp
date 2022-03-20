
Input:
     3
   /  \
  1    2
Output:
3 1 2
1 3 2
Explanation:The connected tree is
        3 ------> NULL
     /    \
    1-----> 2 ------ NULL

/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
void connect(Node *root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=1;i<=sz;i++)
        {
            Node* temp=q.front();
            q.pop();
            if(!q.empty()&&(i!=sz))
            {
                temp->nextRight=q.front();
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}


