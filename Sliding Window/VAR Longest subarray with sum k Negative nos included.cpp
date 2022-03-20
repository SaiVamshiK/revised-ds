Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

 

Example 1:
 

Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        int sum=0;
        int ans=INT_MIN;
        unordered_map<int,int> mp;
        // {sum,index}
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum==k)
            {
                ans=max(ans,i+1);
            }
            if(mp.find(sum-k)!=mp.end())
            {
                int idx=mp[sum-k];
                idx++;
                ans=max(ans,i-idx+1);
            }
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=i;
            }
        }
        if(ans==INT_MIN)
        {
            return 0;
        }
        return ans;
    } 

};
