// your task is to complete the below function
void solve(Node *root,int &ans)
{
    if(root==NULL) return ;
    solve(root->left,ans);
    if(!root->left)
    {
        ans=root->data;   
    }
}
int minValue(Node* root)
{
    int ans;
    solve(root,ans);
    return ans;
}


