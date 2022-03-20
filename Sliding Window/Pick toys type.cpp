You have a row of trees. You are given an integer array fruits where fruits[i] is the type of fruits the ith tree produces.

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets. If you cannot, stop.
Move to the next tree to the right of the current tree. If there is no tree to the right, stop.
Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can collect [1,2,1].

******************************** Longest subarray length with 2 unique characters

class Solution {
public:
    int totalFruit(vector<int>& a) {
        int n=a.size();
        if(n==1)
        {
            return 1;
        }
        int i=0,j=0;
        int cnt=0;
        unordered_map<int,int> mp;
        int ans=0;
        while(j<n)      
        {
            if(mp.find(a[j])==mp.end())
            {
                cnt++;
            }
            mp[a[j]]++;
            if(cnt<2)
            {
                ans=max(ans,j-i+1);
                j++;
            }else if(cnt==2)
            {
                ans=max(ans,j-i+1);
                j++;
            }else{
                while(cnt>2)
                {
                    mp[a[i]]--;
                    if(mp[a[i]]==0)
                    {
                        mp.erase(a[i]);
                        cnt--;
                    }
                    i++;
                }
                if(cnt==2)
                {
                    ans=max(ans,j-i+1);
                }
                j++;
            }
        }
        return ans;
    }
};
