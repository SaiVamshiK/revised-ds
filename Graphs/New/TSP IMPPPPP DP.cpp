
Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. 
Your task is to complete a tour from the city 0 (0 based index) to all other cities such that you 
visit each city atmost once and then at the end come back to city 0 in min cost.
 

Example 1:

Input: cost = {{0,111},{112,0}}
Output: 223
Explanation: We can visit 0->1->0 and 
cost = 111 + 112.
Example 2:

Input: cost = {{0,1000,5000},{5000,0,1000},
{1000,5000,0}}
Output: 3000
Explanation: We can visit 0->1->2->0 and cost 
= 1000+1000+1000 = 3000

class Solution {
public:
int func(vector<vector<int>> &a,int n,int mask,int sv,vector<vector<int>> &dp)
{
    if(mask==(pow(2,n)-1))
    {
        return a[sv][0];
    }
    if(dp[mask][sv]!=-1)
    {
        return dp[mask][sv];
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int temp=((1<<i)&(mask));
        if(temp==0)
        {
            int cur_ans=func(a,n,((1<<i)|(mask)),i,dp)+a[sv][i];
            ans=min(ans,cur_ans);
        }
    }
    return dp[mask][sv]=ans;
}
int total_cost(vector<vector<int>> a){
    int n=a.size();
    int mask=1;
    int size=pow(2,n);
    vector<vector<int>> dp(size+1,vector<int>(n+1,-1));
    return func(a,n,mask,0,dp);
}
};
