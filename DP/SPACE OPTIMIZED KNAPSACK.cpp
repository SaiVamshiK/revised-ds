
You are given a set of coins S. In how many ways can you make sum N assuming you have infinite amount of each coin in the set.

Note : Coins in set S will be unique. Expected space complexity of this problem is O(N).

Example :

Input : 
	S = [1, 2, 3] 
	N = 4

Return : 4

Explanation : The 4 possible ways are
{1, 1, 1, 1}
{1, 1, 2}
{2, 2}
{1, 3}	

const int MOD=1000007;
int Solution::coinchange2(vector<int> &a, int sum) {
    int n=a.size();
    vector<vector<int>> dp(2,vector<int>(sum+1,0));
    for(int i=0;i<2;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=sum;i++)
    {
        dp[0][i]=0;
    }
    int i=1;
    while(i<=n)
    {
        for(int j=1;j<=sum;j++)
        {
            if(a[i-1]<=j)
            {
                int op1=dp[1][j-a[i-1]];
                int op2=dp[0][j];
                dp[1][j]=((op1%MOD)+(op2%MOD))%MOD;
            }else{
                dp[1][j]=(dp[0][j]%MOD);
            }
        }   
        for(int j=0;j<=sum;j++)
        {
            dp[0][j]=dp[1][j];
        }
        i++;
    }
    return dp[1][sum];
}
