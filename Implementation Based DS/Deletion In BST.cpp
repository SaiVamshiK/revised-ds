Given a Binary Search Tree and a node value X. Delete the node with the given value X from the BST. If no node with value x exists, then do not make any change. 

Example 1:

Input:
      2
    /   \
   1     3
X = 12
Output: 1 2 3
Explanation: In the given input there
is no node with value 12 , so the tree
will remain same.

Node* func(Node *root)
{
    Node *cur=root->right;
    while(cur->left)
    {
        cur=cur->left;
    }
    return cur;
}


Node* deletefromBst(Node *root,int x)
{
    if(root)
    {
        if(x<(root->data))
        {
            root->left=deletefromBst(root->left,x);
            return root;
        }else if(x>(root->data))
        {
            root->right=deletefromBst(root->right,x);
            return root;
        }else{
            // no child
            if((!root->left)&&(!root->right))
            {
                free(root);
                return NULL;
            }
            // 1 child
            if(root->left&&(!root->right))
            {
                Node *temp=root->left;
                free(root);
                return temp;
            }
            if(root->right&&(!root->left))
            {
                Node *temp=root->right;
                free(root);
                return temp;
            }
            // 2 child
            Node *inSucc=func(root);
            root->data=inSucc->data;
            root->right=deletefromBst(root->right,root->data);
            return root;
        }   
    }
}

//Function to delete a node from BST.
Node *deleteNode(Node *root,  int X)
{
    return deletefromBst(root,X);
}
