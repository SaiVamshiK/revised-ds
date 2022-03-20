
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
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
        }
        set<pair<int,int>> st;
        for(int i=0;i<n;i++)
        {
            int x=a[i];
            mp[a[i]]--;
            int f1=x-k,f2=x+k;
            if(mp.find(f1)!=mp.end()&&(mp[f1]>0))
            {
                if(x>f1)
                {
                    st.insert({f1,x});
                }else{
                    st.insert({x,f1});   
                }
            }
            if(mp.find(f2)!=mp.end()&&(mp[f2]>0))
            {
                if(x>f2)
                {
                    st.insert({f2,x});
                }else{
                    st.insert({x,f2});   
                }
            }
            mp[a[i]]++;
        }
        return st.size();
    }
};
