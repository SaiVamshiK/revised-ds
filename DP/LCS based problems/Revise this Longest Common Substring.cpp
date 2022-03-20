Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.

*******************************************
Table Filling method

class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[m+1];
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }else{
                    dp[i][j]=0;
                }
            }
        }
        ***********************************************************************************************************************
        // dp[i][j] represents the longest common substring ending at index i for string s1 and ending at index j for string s2
        ***********************************************************************************************************************
        return ans;
    }
};


**************************
Recusive

void func(string s1,string s2,int n,int m,int ans,int &glo)
{
    if(n==0||(m==0))
    {
        return ;
    }
    if(s1[n-1]==s2[m-1])
    {
        ans=ans+1;
        glo=max(ans,glo);
        func(s1,s2,n-1,m-1,ans,glo);
    }else{
        func(s1,s2,n-1,m,0,glo);
        func(s1,s2,n,m-1,0,glo);
    }
}
int longestCommonSubstr (string S1, string S2, int x, int y)
{
    int n=S1.size(),m=S2.size();
    int glo=0;
    func(S1,S2,n,m,0,glo);
    return glo;
}

