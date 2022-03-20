
//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function
bool found(Node *root,int x)
{
    Node *cur=root;
    while(cur!=NULL)
    {
        if(x<(cur->data))
        {
            cur=cur->left;
        }else if(x>(cur->data))
        {
            cur=cur->right;
        }else{
            return true;
        }
    }
    return false;
}
void preorder(Node *r1,Node *r2,int x,int &ans)
{
    if(r1==NULL)
    {
        return ;
    }
    int search=x-r1->data;
    if(found(r2,search))
    {
        ans++;
    }
    preorder(r1->left,r2,x,ans);
    preorder(r1->right,r2,x,ans);
}
void func(Node *r1,Node *r2,int x,int &ans)
{
    preorder(r1,r2,x,ans);
}
int countPairs(Node* root1, Node* root2, int x)
{
    int ans=0;
    func(root1,root2,x,ans);
    return ans;
}
