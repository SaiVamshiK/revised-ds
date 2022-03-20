
/*

The structure of a BST node is as follows:

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

void func(Node *root,int l,int h,int &ans)
{
    if(root==NULL) return ;
    int d=root->data;
    if(l<=d&&d<=h)
    {
        ans++;
    }
    if(l>root->data)
    {
        // right
        func(root->right,l,h,ans);
    }
    else if(h<root->data)
    {
        // left
        func(root->left,l,h,ans);
    }else{
        func(root->left,l,h,ans);
        func(root->right,l,h,ans);
    }
}
int getCountOfNode(Node *root, int l, int h)
{
    int ans=0;
    func(root,l,h,ans);
    return ans;
}




