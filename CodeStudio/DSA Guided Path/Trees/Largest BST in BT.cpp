/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

struct Node{
  	bool isBst;
    int size;
    int minVal;
    int maxVal;
};

bool isLeaf(TreeNode<int>* root)
{
	if((!root->left)&&(!root->right))
    {
        return true;
    }
    return false;
}

Node func(TreeNode<int>* root,int &size)
{
    if(isLeaf(root))
    {
        Node ans;
        ans.isBst=true;
        ans.size=1;
        ans.minVal=root->data;
        ans.maxVal=root->data;
        size=max(size,ans.size);
        return ans;
    }
    int curValue=(root->data);
    if((!root->left)&&(root->right))
    {
        Node right=func(root->right,size);
        if(right.isBst&&(curValue<right.minVal))
        {
            Node ans;
            ans.isBst=true;
            ans.size=1+right.size;
            ans.minVal=curValue;
            ans.maxVal=right.maxVal;
            size=max(size,ans.size);
            return ans;
        }else{
            Node ans;
            ans.isBst=false;
            ans.size=-1;
            ans.minVal=-1;
            ans.maxVal=-1;
            return ans;
        }
    }else if((root->left)&&(!root->right))
    {
        Node left=func(root->left,size);
        if(left.isBst&&(left.maxVal<curValue))
        {
            Node ans;
            ans.isBst=true;
            ans.size=1+left.size;
            ans.minVal=left.minVal;
            ans.maxVal=curValue;
            size=max(size,ans.size);
            return ans;
        }else{
            Node ans;
            ans.isBst=false;
            ans.size=-1;
            ans.minVal=-1;
            ans.maxVal=-1;
            return ans;
        }
    }else{
        Node left=func(root->left,size);
        Node right=func(root->right,size);
        if((left.isBst)&&(right.isBst)&&
           		((left.maxVal<=curValue)&&(curValue<=right.minVal)))
        {
            Node ans;
            ans.isBst=true;
            ans.size=1+left.size+right.size;
            ans.minVal=left.minVal;
            ans.maxVal=right.maxVal;
            size=max(size,ans.size);
            return ans;
        }else{
            Node ans;
            ans.isBst=false;
            ans.size=-1;
            ans.minVal=-1;
            ans.maxVal=-1;
            return ans;
        }
    }
}

int largestBST(TreeNode<int>* root) 
{
    int size=0;
    func(root,size);
    return size;
}



