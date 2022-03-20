
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals 
you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

struct Node{
    int si,ei;
};
bool comparator(Node a,Node b)
{
    return a.si<b.si;
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        Node *a=new Node[n];
        for(int i=0;i<n;i++)
        {
            a[i].si=intervals[i][0];
            a[i].ei=intervals[i][1];
        }
        sort(a,a+n,comparator);
        int cnt=0;
        int *dp=new int[n];
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            int maxVal=INT_MIN;
            for(int j=i-1;j>=0;j--)
            {
                Node cur=a[j];
                if(a[j].ei<=(a[i].si))
                {
                    maxVal=max(maxVal,dp[j]+1);
                }
            }
            if(maxVal!=INT_MIN)
            {
                dp[i]=maxVal;
            }else{
                dp[i]=1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
        }
        return n-ans;
    }
};
