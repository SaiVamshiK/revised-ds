
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4

class Solution {
public:
    bool isValid(vector<int> &piles,int n,int h,int k)
    {
        int val=0;
        for(int i=0;i<n;i++)
        {
            val+=(piles[i]/k);
            if((piles[i]%k)!=0)
            {
                val++;
            }
            if(val>h) 
            {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int start=1,end=INT_MIN;
        for(int i=0;i<n;i++)
        {
            end=max(end,piles[i]);
        }
        if(h==n)
        {
            return end;
        }
        int ans;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(isValid(piles,n,h,mid))
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
