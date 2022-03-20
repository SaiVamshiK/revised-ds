
/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
void solve(Node *root,Node* &head,Node* &prev)
{
    if(root!=NULL)
    {
        solve(root->left,head,prev);
        if(prev==NULL)
        {
            head=root;
            prev=root;
        }else{
            prev->right=root;
            root->left=prev;
            prev=root;
        }
        solve(root->right,head,prev);
    }
}
Node * bToDLL(Node *root)
{
    Node *head=NULL,*prev=NULL;
    solve(root,head,prev);
    return head;
}



