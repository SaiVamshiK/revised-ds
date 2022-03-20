
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
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

// return true if the given tree is a BST, else return false

bool func(Node *root,int min_val,int max_val)
{
    if(root==NULL)
    {
        return true;
    }
    int d=root->data;
    if((min_val<=d)&&(d<=max_val))
    {
        return func(root->left,min_val,d-1)&&func(root->right,d+1,max_val);
    }
    return false;
}

bool isBST(Node* root) {
    int x=INT_MIN,y=INT_MAX;
    return func(root,x,y);
}


