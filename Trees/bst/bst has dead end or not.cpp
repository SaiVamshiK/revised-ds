/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
void func(Node *root,int min_val,int max_val,bool &ans)
{
    if(root==NULL) return ;
    if(min_val>=max_val)
    {
        ans=false;
        return ;
    }
    func(root->left,min_val,root->data-1,ans);
    func(root->right,root->data+1,max_val,ans);
}
bool isDeadEnd(Node *root)
{
    bool ans=true;
    func(root,1,INT_MAX,ans);
    return !ans;
}




