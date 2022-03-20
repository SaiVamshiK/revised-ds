
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]

int Solution::maxProduct(const vector<int> &A) {
    int n=A.size();
    int max_eh=A[0],min_eh=A[0],ans=A[0];
    for(int i=1;i<n;i++)
    {
        int temp=max_eh;
        max_eh=max(A[i],max(max_eh*A[i],min_eh*A[i]));
        ans=max(ans,max_eh);
        min_eh=min(A[i],min(temp*A[i],min_eh*A[i]));
    }
    return ans;
}

