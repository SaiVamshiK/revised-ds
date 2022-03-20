
//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
pair<Node*,bool > find(Node *root,int &k,int val,Node* &ans)
{
    if(root==NULL) return {NULL,false};
    if(root->data==val)
    {
        return {root,true};
    }
    pair<Node*,bool > left=find(root->left,k,val,ans);
    pair<Node*,bool > right=find(root->right,k,val,ans);
    if(left.second)
    {
        k--;
        if(k==0)
        {
            ans=root;
        }
        return left;
    }
    if(right.second){
        k--;
        if(k==0)
        {
            ans=root;
        }
        return right;
    }
    return {NULL,false};
}
int kthAncestor(Node *root, int k, int node)
{
    Node *ans=NULL;
    find(root,k,node,ans);
    if(ans==NULL) return -1;
    return ans->data;
}



