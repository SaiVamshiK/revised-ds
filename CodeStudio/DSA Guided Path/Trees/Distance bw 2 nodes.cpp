
Problem Statement
Given a binary tree and the value of two nodes, find the distance between the given two nodes of the Binary Tree.
Distance between two nodes is defined as the minimum number of edges in the path from one node to another.
Input Format:
The first line of input contains an integer ‘T’ representing the number of test cases. Then the test cases follow.

The first line of each test case contains elements in the level order form, and all the node values in the given tree are unique. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.

The second line of each test case contains two single-spaced integers, Node 1 and Node 2, representing the values of the two nodes.

For example, the input for the tree depicted in the below image would be:

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

bool search(TreeNode<int> *root, int key)
{
	if(root==NULL)
    {
        return false;
    }
    if((root->val)==key)
    {
        return true;
    }
    bool left=search(root->left,key);
    if(left)
    {
        return true;
    }
    bool right=search(root->right,key);
    return right;
}

TreeNode<int>* findLCA(TreeNode<int> *root,int val1,int val2)
{
    if(root==NULL)
    {
        return NULL;
    }
    int cur=(root->val);
    if(cur==val1||(cur==val2))
    {
        return root;
    }
    TreeNode<int> *left=findLCA(root->left,val1,val2);
    TreeNode<int> *right=findLCA(root->right,val1,val2);
    if(left&&right)
    {
        return root;
    }else if(left)
    {
        return left;
    }else{
        return right;
    }
}

int findDist(TreeNode<int> *root,int x)
{
    if(root==NULL)
    {
        return -1;
    }
    int cur=root->val;
    if(cur==x)
    {
        return 0;
    }
    int left=findDist(root->left,x);
    int right=findDist(root->right,x);
    if(right!=-1)
    {
        return right+1;
    }else if(left!=-1){
        return left+1;
    }else{
        return -1;
    }
}

int findDistanceBetweenNodes(TreeNode<int> *root, int val1, int val2)
{
    if(search(root,val1)&&(search(root,val2)))
    {
        TreeNode<int> *lca=findLCA(root,val1,val2);
        int dist1=findDist(lca,val1);
        int dist2=findDist(lca,val2);
        return dist1+dist2;
    }else{
        return -1;
    }
}
















