/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
Node* LCA(Node *root,int a,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==a||(root->data==b))
    {
        return root;
    }
    Node *l=LCA(root->left,a,b);
    Node *r=LCA(root->right,a,b);
    if(l&&r)
    {
        return root;
    }
    if(l==NULL&&(r!=NULL))
    {
        return r;
    }
    if(l!=NULL&&(r==NULL))
    {
        return l;
    }
    return NULL;
}
pair<bool,int> solve(Node *root,int a)
{
    if(root==NULL)
    {
        return {false,0};
    }
    if(root->data==a)
    {
        return {true,1};
    }
    pair<bool,int> l=solve(root->left,a);
    pair<bool,int> r=solve(root->right,a);
    if(l.first)
    {
        return {true,1+l.second};
    }
    if(r.first)
    {
        return {true,1+r.second};
    }
    return {false,0};
}
int findDist(Node* root, int a, int b) {
    Node *lca=LCA(root,a,b);
    int h1=solve(lca,a).second;
    int h2=solve(lca,b).second;
    return h1+h2-2;
}




