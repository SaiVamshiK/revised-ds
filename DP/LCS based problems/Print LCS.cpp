********************
Printing LCS with the table
// function to find longest common subsequence
int func(string s1,string s2,int n,int m,int **dp)
{
    if(n==0||(m==0))
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1])
    {
        int temp=func(s1,s2,n-1,m-1,dp);
        return dp[n][m]=1+temp;
    }else{
        int temp1=func(s1,s2,n,m-1,dp),temp2=func(s1,s2,n-1,m,dp);
        return dp[n][m]=max(temp1,temp2);
    }
}
int lcs(int x, int y, string s1, string s2){
    int n=s1.size(),m=s2.size();
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[m+1];
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=-1;
        }
    }
    func(s1,s2,n,m,dp);
    string ans="";
    int i=n,j=m;
    while((i!=0)&&(j!=0))
    {
        if(s1[i-1]==s2[j-1])
        {
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j]>(dp[i][j-1]))
            {
                i--;
            }else{
                j--;
            }
        }
    }
    // ans is the LCS now
    return ans.size();
}

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int j=1;j<=m;j++)
        {
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string ans="";
        int i=n,j=m;
        while(i>0&&(j>0))
        {
            if(s1[i-1]==s2[j-1])
            {
                ans.push_back(s1[i-1]);
                i--;j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1])
                {
                    i--;
                }else{
                    j--;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
        return ans.size();
    }
};




