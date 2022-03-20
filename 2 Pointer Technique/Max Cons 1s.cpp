Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int n=a.size();
        bool started=false;
        int len=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!started&&(a[i]==1))
            {
                started=true;
                len++;
            }else if(started&&(a[i]==1))
            {
                len++;
            }else{
                ans=max(ans,len);
                len=0;started=false;
            }
        }
        ans=max(ans,len);
        return ans;
    }
};
