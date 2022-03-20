Two kingdoms are on a war right now, kingdom X and kingdom Y. As a war specialist of kingdom X, you scouted kingdom Y area.

A kingdom area is defined as a N x M grid with each cell denoting a village.
Each cell has a value which denotes the strength of each corresponding village.
The strength can also be negative, representing those warriors of your kingdom who were held hostages.

There’s also another thing to be noticed.

The strength of any village on row larger than one (2<=r<=N) is stronger or equal to the strength of village which is exactly above it.
The strength of any village on column larger than one (2<=c<=M) is stronger or equal to the strength of vilage which is exactly to its left.
(stronger means having higher value as defined above).
So your task is, find the largest sum of strength that you can erase by bombing one sub-matrix in the grid.

Input format:

First line consists of 2 integers N and M denoting the number of rows and columns in the grid respectively.
The next N lines, consists of M integers each denoting the strength of each cell.

1 <= N <= 1500
1 <= M <= 1500
-200 <= Cell Strength <= 200
Output:

The largest sum of strength that you can get by choosing one sub-matrix.

int kadane(int *a,int n)
{
    int meh=0,msf=INT_MIN;
    for(int i=0;i<n;i++)
    {
        meh+=a[i];
        if(meh<a[i])
        {
            meh=a[i];
        }
        msf=max(msf,meh);
    }
    return msf;
}
int Solution::solve(vector<vector<int> > &a) {
    int n=a.size(),m=a[0].size();
    int ans=INT_MIN;
    int *temp=new int[n];
    for(int l=0;l<m;l++)
    {
        for(int i=0;i<n;i++)
        {
            temp[i]=a[i][l];
        }
        ans=max(ans,kadane(temp,n));
        for(int r=l+1;r<m;r++)
        {
            for(int k=0;k<n;k++)
            {
                temp[k]+=a[k][r];
            }
            ans=max(ans,kadane(temp,n));  
        }
    }
    return ans;
}

