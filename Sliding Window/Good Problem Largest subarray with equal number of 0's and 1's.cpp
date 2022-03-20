Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

Example 1:

Input:
N = 4
A[] = {0,1,0,1}
Output: 4
Explanation: The array from index [0...3]
contains equal number of 0's and 1's.
Thus maximum length of subarray having
equal number of 0's and 1's is 4.

***
Make all 0's as -1 and now task is to find out largest subarray with 0 sum

int maxLen(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            a[i]=-1;
        }
    }
    int ans=INT_MIN;
    int sum=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
        if(sum==0)
        {
            ans=max(ans,i+1);
        }
        if(mp.find(sum)!=mp.end())
        {
            auto itr=mp.find(sum);
            int idx=itr->second;
            idx++;
            ans=max(ans,i-idx+1);
        }
        if(mp.find(sum)==mp.end())
        {
            mp[sum]=i;
        }
    }
    return (ans!=INT_MIN)?ans:0;
}


