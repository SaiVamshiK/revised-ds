Problem Statement
You are given a Binary Search Tree with its root node and a range. Your task is to find the sum of all the values of the nodes whose values lie in the given range(L, R) inclusive.
A Binary Search tree is a tree in which all the nodes follow the following properties:
1. The value of a node of the left sub-tree is less than the value of the node.
2. The value of a node of the right sub-tree is greater than or equal to the value of the node.


/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void func(TreeNode<int> *root,int low,int high,int &sum)
{
    if(!root)
    {
        return ;
    }
    int curValue=(root->data);
    if((low<=curValue)&&(curValue<=high))
    {
        sum+=curValue;
        func(root->left,low,high,sum);
        func(root->right,low,high,sum);
    }else{
        if(curValue<low)
        {
            func(root->right,low,high,sum);
        }else if(curValue>high){
            func(root->left,low,high,sum);
        }
    }
}

int rangeSum(TreeNode<int> *root, int low, int high)
{
    int sum=0;
    func(root,low,high,sum);
    return sum;
}



