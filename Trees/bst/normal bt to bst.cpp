//User function template for C++

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

// The given root is the root of the Binary Tree
// Return the root of the generated BST


Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1

void inorder(Node *root,vector<int> &arr)
{
    if(root==NULL)
    {
        return ;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
void solve(Node *root,vector<int> arr,int &idx,int n)
{
    if(root==NULL||idx==n)
    {
        return ;
    }
    solve(root->left,arr,idx,n);
    root->data=arr[idx];
    idx++;
    solve(root->right,arr,idx,n);
}
Node *binaryTreeToBST (Node *root)
{
    vector<int> arr;
    inorder(root,arr);
    sort(arr.begin(),arr.end());
    int idx=0;
    solve(root,arr,idx,arr.size());
    return root;
}
