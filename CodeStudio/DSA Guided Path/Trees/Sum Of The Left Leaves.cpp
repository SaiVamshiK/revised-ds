
Problem Statement
Given a binary tree with ‘root’. Your task is to find the sum of all the left leaf nodes.
Properties of leaf:-
In a binary tree, a leaf is a node such that it does not have any children. Node ‘1’ is always the root of the binary tree. 
Left leaves are those nodes that are the left child of their parent and a leaf node.

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

bool isLeaf(TreeNode<int> *root)
{
    if((!root->left)&&(!root->right))
    {
        return true;
    }
    return false;
}

void func(TreeNode<int> *root,bool isLeft,int &sum)
{
    if(!root)
    {
        return ;
    }
    if(isLeaf(root))
    {
        if(isLeft)
        {
            sum=sum+(root->val);
        }
        return ;
    }
    func(root->left,true,sum);
    func(root->right,false,sum);
}

int sumOfLeftLeaves(TreeNode<int> *root)
{
	int sum=0;
    if(!root)
    {
        return sum;
    }
    func(root->left,true,sum);
    func(root->right,false,sum);
    return sum;
}
