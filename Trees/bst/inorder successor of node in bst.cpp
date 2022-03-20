
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// returns the inorder successor of the Node x in BST (rooted at 'root')
Node * inOrderSuccessor(Node *root, Node *x)
{
    Node *t=root,*ans=NULL;
    int node_data=x->data;
    Node *last_left=NULL;
    while(t!=NULL)
    {
        if(t->data>node_data)
        {
            last_left=t;
            t=t->left;
        }else if((t->data)<node_data)
        {
            t=t->right;
        }else{
            ans=t;
            break;
        }
    }
    if(ans==NULL)
    {
        return nullptr;
    }
    if(ans->right==NULL)
    {
        return last_left;
    }
    ans=ans->right;
    while(ans->left)
    {
        ans=ans->left;
    }
    return ans;
}


