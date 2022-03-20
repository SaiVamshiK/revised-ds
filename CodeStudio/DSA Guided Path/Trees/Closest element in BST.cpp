Problem Statement
You have been given a binary search tree of integers with ‘N’ nodes and a target integer value ‘K’. Your task is to find the closest element to the target ‘K’ in the given binary search tree.
A node in BST is said to be the closest to the target if its absolute difference with the given target value ‘K’ is minimum. In the case of more than one closest element, return the element with a minimum value.
A binary search tree (BST) is a binary tree data structure with the following properties.

/*************************************************************
    Following is the Binary Search Tree node structure

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

        ~BinaryTreeNode() {
            
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/

void func(BinaryTreeNode<int>* root,int k,int &diff,int &ans)
{
    if(!root)
    {
        return ;
    }
    int curValue=(root->data);
    int curDiff=abs(curValue-k);
    if(curDiff<diff)
    {
        diff=curDiff;
        ans=root->data;
    }else if(curDiff==diff)
    {
        ans=min(ans,root->data);
    }
    if(curValue>k)
    {
        func(root->left,k,diff,ans);
    }else if(curValue<k){
    	func(root->right,k,diff,ans);
    }
}

int findClosestElement(BinaryTreeNode<int>* root, int k){
	int diff=INT_MAX,ans=-1;
    func(root,k,diff,ans);
    return ans;
}



