
Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.


Example 1:

Input:N = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.

****************************************************
Recurence Relation Is: f(n)=f(n-1)+((n-1 C 1)*(f(n-2)));
Choosing 1 friend from n-1 remaining people
const long MOD=1e9+7;

class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        long *dp=new long[n+1];
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            int t1=(dp[i-1]%MOD);
            int t2=(((i-1)%MOD)*(dp[i-2]%MOD))%MOD;
            dp[i]=((t1%MOD)+(t2%MOD))%MOD;
        }
        return dp[n];
    }
};    
 
 
