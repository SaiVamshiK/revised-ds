
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
// { ht,dia }
pair<int,int> func(Node *root)
{
    if(root==NULL)
    {
        pair<int,int> ans;
        ans={0,0};
        return ans;
    }
    pair<int,int> left=func(root->left);
    pair<int,int> right=func(root->right);
    int height=max(left.first,right.first)+1;
    int op1=left.first+right.first;
    int op2=left.second;
    int op3=right.second;
    return {height,max(op1,max(op2,op3))};
}
int diameter(Node* node) {
    return func(node).second+1;
}


