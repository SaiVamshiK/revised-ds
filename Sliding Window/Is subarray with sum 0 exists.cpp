Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.

//Complete this function
bool subArrayExists(int a[], int n)
{
    int sum=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
        if(sum==0)
        {
            return true;
        }
        if(mp.find(sum)!=mp.end())
        {
            return true;
        }
        mp[sum]=i;
    }
    return false;
}



