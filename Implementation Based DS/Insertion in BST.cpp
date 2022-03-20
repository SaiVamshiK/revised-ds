
Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. 
Note: If K is already present in the BST, don't modify the BST.


Example 1:

Input:
     2
   /   \
  1     3
K = 4
Output: 1 2 3 4
Explanation: After inserting the node 4
Inorder traversal will be 1 2 3 4.


void func(Node *root,Node *par,int x,int c)
{
    if(root==NULL)
    {
        Node *temp=new Node(x);
        if(c==0)
        {
            par->left=temp;
            return ;
        }else{
            par->right=temp;
            return ;
        }
    }
    int cur=root->data;
    if(x<cur)
    {
        func(root->left,root,x,0);
    }else if(x>cur)
    {
        func(root->right,root,x,1);
    }else{
        return ;
    }
}
//Function to insert a node in a BST.
Node* insert(Node* root, int x)
{
    func(root,NULL,x,-1);
    return root;
}
