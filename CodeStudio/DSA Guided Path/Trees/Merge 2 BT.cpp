
Problem Statement
You are given roots of two binary trees, ‘ROOT1’ and ‘ROOT2’. You need to merge the two trees into a new binary tree. 
The merge rule is that if the two nodes overlap, then the sum of the two nodes values up as the new value of the merged node. 
Otherwise, the NOT null node will be used as the node of the new tree. Your task is to return the merged tree i.e. head of the new tree.

/*************************************************************
    
    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        ~BinaryTreeNode() {
        if (left){
         delete left;
        }
        if (right){
        delete right;
        }
  }
    };

*************************************************************/

BinaryTreeNode* merge(BinaryTreeNode* r1,BinaryTreeNode* r2)
{
    if((!r1)&&(!r2))
    {
        return nullptr;
    }
    if((r1)&&(!r2))
    {
        return r1;
    }
    if((!r1)&&(r2))
    {
        return r2;
    }
    int v1=(r1->data),v2=(r2->data);
    r1->data+=(v2);
    r1->left=merge(r1->left,r2->left);
    r1->right=merge(r1->right,r2->right);
    return r1;
}

BinaryTreeNode* mergeTrees(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
    return merge(root1,root2);
}



