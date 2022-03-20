
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

class Solution {
public:
    bool isValid(int maxSum,vector<int> &a,int n,int m)
    {
        int cnt=1,cur=0;
        for(int i=0;i<n;i++) 
        {
            cur=cur+a[i];
            if(cur>maxSum)
            {
                cnt++;
                cur=0;
                if((cur+a[i])<=maxSum)
                {
                    cur=cur+a[i];
                }else{
                    return false;
                }
            }
            if(cnt>m)
            {
                return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& a, int m) {
        int n=a.size();
        int start=INT_MIN,end=0;
        for(int i=0;i<n;i++)
        {
            start=max(start,a[i]);
            end=end+a[i];
        }
        int ans=-1;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(isValid(mid,a,n,m))
            {
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};
