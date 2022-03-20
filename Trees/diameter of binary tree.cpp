/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/* Computes the diameter of binary tree with given root.  */
int height(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=height(root->left),rh=height(root->right);
    return 1+(max(lh,rh));
}
int func(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    int op1=rh+lh;
    int op2=func(root->left);
    int op3=func(root->right);
    return max(op1,max(op2,op3));
}
int diameter(Node* node) {
    return func(node)+1;
}

