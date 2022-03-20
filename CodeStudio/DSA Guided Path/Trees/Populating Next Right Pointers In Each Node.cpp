Problem Statement
You have been given a complete binary tree of ‘N’ nodes. The nodes are numbered 1 to ‘N’.
You need to find the ‘next’ node that is immediately right in the level order form for each node in the given tree.
Note :
1. A complete binary tree is a binary tree in which nodes at all levels except the last level have two children and nodes at the last level have 0 children.
2. Node ‘U’ is said to be the next node of ‘V’ if and only if  ‘U’ is just next to ‘V’ in tree representation.
3. Particularly root node and rightmost nodes have ‘next’ node equal to ‘Null’ 
4. Each node of the binary tree has three-pointers, ‘left’, ‘right’, and ‘next’. Here ‘left’ and ‘right’ are the children of node and ‘next’ is one extra pointer that we need to update.

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode<T> *next;


        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
            next = NULL;
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

void connectNext(TreeNode<int> *root)
{
    if(!root||(isLeaf(root)))
    {
        return ;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=1;i<=sz;i++)
        {
            TreeNode<int> *curPtr=q.front();
            q.pop();
            if(i!=sz)
            {
             	if(!q.empty())
                {
                 	curPtr->next=q.front();   
                }   
            }
            if(curPtr->left)
            {
                q.push(curPtr->left);
            }
            if(curPtr->right)
            {
                q.push(curPtr->right);
            }
        }
    }
}


















