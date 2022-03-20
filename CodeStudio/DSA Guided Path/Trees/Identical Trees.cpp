/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
		
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

bool func(BinaryTreeNode<int>* r1, BinaryTreeNode<int>* r2)
{
    if((!r1)&&(!r2))
    {
        return true;
    }
    if(((!r1)&&(r2))||((r1)&&(!r2)))
    {
        return false;
    }
    int c1=r1->data,c2=r2->data;
    if(c1!=c2)
    {
        return false;
    }
    return func(r1->left,r2->left)&&func(r1->right,r2->right);
}

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    return func(root1,root2);
}





