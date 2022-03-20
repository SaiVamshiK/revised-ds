
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i < j < nums.length
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        int n=a.size();
        if(n==1)
        {
            return 0;
        }
        k=abs(k);
        sort(a.begin(),a.end());
        int i=0,j=1;
        int cnt=0;
        while(j<n)
        {
            int cur=a[j]-a[i];
            if(cur<k)
            {
                j++;
            }else if(cur>k)
            {
                i++;
            }else{
                cnt++;
                int starti=a[i];
                int startj=a[j];
                while(i<n&&(a[i]==starti))
                {
                    i++;
                }
                while(j<n&&(a[j]==startj))
                {
                    j++;
                }
            }
            if(i==j)
            {
                j++;
            }
        }
        return cnt;
    }
};
