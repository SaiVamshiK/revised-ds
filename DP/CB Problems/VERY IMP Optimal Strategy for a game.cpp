
Given an array of scores that are non-negative integers. 
Player 1 picks one of the numbers from either end of the array followed by the player 2 
and then player 1 and so on. Each time a player picks a number, that number will not be 
available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:

Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, 
then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.

class Solution {
public:
    int func(vector<int>& a,int i,int j,vector<vector<int>> &dp)
    {
        if(i==j)
        {
            return a[i];
        }
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int op1=a[i]+min(func(a,i+2,j,dp),func(a,i+1,j-1,dp));
        int op2=a[j]+min(func(a,i+1,j-1,dp),func(a,i,j-2,dp));
        return dp[i][j]=max(op1,op2);
    }
    bool PredictTheWinner(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans=func(a,0,n-1,dp),sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        int other=sum-ans;
        if(ans>=other)
        {
            return true;
        }
        return false;
    }
};







