
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
struct block{
    bool isBst;
    int size;
    int min_val;
    int max_val;
    block()
    {
        isBst=true;
        size=0;
        min_val=INT_MIN;
        max_val=INT_MAX;
    }
};
block func(Node *root,int &ans)
{
    if(root==NULL)
    {
        block k;
        return k;
    }
    block left=func(root->left,ans);
    block right=func(root->right,ans);
    if(left.isBst&&right.isBst)
    {
        int d=root->data;
        if(left.max_val==INT_MAX&&right.max_val==INT_MAX)
        {
            block ret;
            ret.isBst=true;
            ret.size=1;
            ans=max(ans,ret.size);
            ret.max_val=d;
            ret.min_val=d;
            return ret;
        }
        if(left.max_val==INT_MAX&&right.max_val!=INT_MAX)
        {
            if(d<right.min_val)
            {
                block ret;
                ret.isBst=true;
                ret.size=right.size+1;
                ans=max(ans,ret.size);
                ret.min_val=d;
                ret.max_val=right.max_val;
                return ret;
            }
            block ret;
            ret.isBst=false;
            ret.size=1;
            ans=max(ans,ret.size);
            ret.max_val=0;
            ret.min_val=0;
            return ret;
        }
        if(left.max_val!=INT_MAX&&(right.max_val==INT_MAX))
        {
            if(d>left.max_val)
            {
                block ret;
                ret.isBst=true;
                ret.size=left.size+1;
                ans=max(ans,ret.size);
                ret.min_val=left.min_val;
                ret.max_val=d;
                return ret;
            }
            block ret;
            ret.isBst=false;
            ret.size=1;
            ans=max(ans,ret.size);
            ret.max_val=0;
            ret.min_val=0;
            return ret;
        }
        if((left.max_val<d)&&(d<right.min_val))
        {
            block ret;
            ret.isBst=true;
            ret.size=left.size+right.size+1;
            ans=max(ans,ret.size);
            ret.min_val=left.min_val;
            ret.max_val=right.max_val;
            return ret;
        }
        block ret;
        ret.isBst=false;
        ret.size=1;
        ans=max(ans,ret.size);
        ret.max_val=0;
        ret.min_val=0;
        return ret;
    }
    block ret;
    ret.isBst=false;
    ret.size=1;
    ans=max(ans,ret.size);
    ret.min_val=INT_MIN;
    ret.max_val=INT_MAX;
    return ret;
}
int largestBst(Node *root)
{
    int ans=INT_MIN;
    func(root,ans);
    return ans;
}




