
Given an integer array bloomDay, an integer m and an integer k.

We need to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let's see what happened in the first three days. x means flower bloomed and _ means flower didn't bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet .
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

typedef long long ll;
class Solution {
public:
    //  isValid(mid,bloomDay,n,m,k)
    bool isValid(ll days,vector<int> &bloomDay,ll n,int bouquets,int flowers)
    {
        int cnt=0;
        int cur_size=0;
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=days)
            {
                cur_size++;
                if(cur_size==flowers)
                {
                    cnt++;
                    cur_size=0;
                }
            }else{
                cur_size=0;
            }
            if(cnt==bouquets)
            {
                return true;
            }
        }
        if(cur_size==flowers)
        {
            cnt++;
        }
        if(cnt<bouquets)
        {
            return false;
        }
        return true;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        ll n=bloomDay.size();
        if((m*k)>n)
        {
            return -1;
        }
        ll start=1,end=0;
        for(ll i=0;i<n;i++)
        {
            end=end+bloomDay[i];
        }
        ll ans=-1;
        while(start<=end)
        {
            ll mid=start+((end-start)/2);
            if(isValid(mid,bloomDay,n,m,k))
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
