
1. You are given an array(arr) of integers and a number k.
2. You have to find maximum subarray sum in the given array.
3. The subarray must have at least k elements.
Input Format
A number N
a1
a2.. N integers
A number K
Output Format
A number representing maximum subarray sum with subarray having at least K elements.

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
    int k;
    cin>>k;
    int *maxEndingHere=new int[n];
    int curSum=0;
    for(int i=0;i<n;i++)
    {
        if((curSum+a[i])>(a[i]))
        {
            curSum+=a[i];
        }else{
            curSum=a[i];
        }
        maxEndingHere[i]=curSum;
    }
    int i=0,j=0;
    int windowSum=0;
    int maxSum=INT_MIN;
    while(j<n)
    {
        windowSum+=a[j];
        if((j-i+1)<k)
        {
            j++;
        }else if((j-i+1)==k)
        {
            maxSum=max(maxSum,windowSum);
            if((i-1>=0))
            {
                maxSum=max(maxSum,windowSum+maxEndingHere[i-1]);
            }
            windowSum-=a[i];
            i++;
            j++;
        }
    }
    cout<<maxSum;
    
}



















