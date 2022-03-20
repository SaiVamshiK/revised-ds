Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] 
that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
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
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
