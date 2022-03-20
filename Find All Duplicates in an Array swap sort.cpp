
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and
each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

SWAP SORT CAN BE APPILED ONLY IF ALL ELEMENTS ARE IN RANGE OF 1 TO N

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        int n=a.size();
        int i=0;
        while(i<n)
        {
            if(a[i]==(i+1))
            {
                i++;
            }else{
                int val=a[i];
                int pos=a[i]-1;
                if(a[i]!=a[pos])
                {
                    swap(a[i],a[pos]);
                }else{
                    i++;
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=(i+1))
            {
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};
