
1. You are given a number n, representing the number of elements.
2. You are given n numbers, representing the contents of array of length n.
3. You are required to print the sum of elements of the increasing subsequence with maximum sum for the array.
Input Format
A number n
.. n more elements
Output Format
A number representing the sum of elements of the increasing subsequence with maximum sum for the array.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int *dp=new int[n];
    dp[0]=a[0];
    for(int i=1;i<n;i++)
    {
        int maxSum=INT_MIN;
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]<=a[i])
            {
                maxSum=max(maxSum,dp[j]+a[i]);
            }
        }
        if(maxSum==INT_MIN)
        {
            dp[i]=a[i];
        }else{
            dp[i]=maxSum;
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}
