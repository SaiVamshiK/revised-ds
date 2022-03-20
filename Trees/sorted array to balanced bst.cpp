TreeNode* func(const vector<int> &A,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=start+((end-start)/2);
    TreeNode *temp=new TreeNode(A[mid]);
    temp->left=func(A,start,mid-1);
    temp->right=func(A,mid+1,end);
    return temp;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n=A.size();
    return func(A,0,n-1);
}

