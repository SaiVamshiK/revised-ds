/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
Node* lca(Node *root,int a,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==a||(root->data==b))
    {
        return root;
    }
    Node *left=lca(root->left,a,b);
    Node *right=lca(root->right,a,b);
    if(left&&right)
    {
        return root;
    }
    if(left)
    {
        return left;
    }
    if(right)
    {
        return right;
    }
    return NULL;
}
bool ht(Node *root,int target,int &ans)
{
    if(root==NULL) return false;
    if(root->data==target)
    {
        return true;
    }
    bool left=ht(root->left,target,ans);
    bool right=ht(root->right,target,ans);
    if(left)
    {
        ans++;
        return true;
    }
    if(right)
    {
        ans++;
        return true;
    }
    return false;
}
int findDist(Node* root, int a, int b) {
    Node *LCA=lca(root,a,b);
    int h1=0,h2=0;
    ht(LCA,a,h1);
    ht(LCA,b,h2);
    return h1+h2;
}



