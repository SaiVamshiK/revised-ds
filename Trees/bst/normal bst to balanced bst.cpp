/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/
// Your are required to complete this function
// function should return root of the modified BST
void inorder(Node *root,vector<int> &ans)
{
    if(root==NULL) return ;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
Node* func(vector<int> a,int l,int r)
{
    if(l>r)
    {
        return NULL;
    }
    int mid=l+((r-l)/2);
    Node *root=new Node(a[mid]);
    root->left=func(a,l,mid-1);
    root->right=func(a,mid+1,r);
    return root;
}
Node* buildBalancedTree(Node* root)
{
	vector<int > arr;
	inorder(root,arr);
	Node *ans=func(arr,0,arr.size()-1);
	return ans;
}

