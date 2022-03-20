struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// Return a integer of integers having all the nodes in both the BSTs in a sorted order.
void inorder(Node *root,vector<int> &ans)
{
    if(root==NULL)
    {
        return ;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
vector<int> merge(Node *root1, Node *root2)
{
    vector<int> ans;
    inorder(root1,ans);
    inorder(root2,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
