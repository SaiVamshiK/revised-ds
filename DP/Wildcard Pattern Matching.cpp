 Given two strings 'str' and a wildcard pattern 'pattern' of length N and M respectively,  
 You have to print '1' if the wildcard pattern is matched with str else print '0' .

The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

Note: The matching should cover the entire str (not partial str).
 
 bool isMatching(string &s,string &pat,int i,int n,
                        int j,int m,vector<vector<int>> &dp)
    {
        if(i>n||(j>m))
        {
            return false;
        }
        if(i==n&&(j==m))
        {
            return true;
        }
        if(j==m)
        {
            return false;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        char ch=pat[j];
        if(ch!='*'&&(ch!='?'))
        {
            if(ch==s[i])
            {
                bool op1=isMatching(s,pat,i+1,n,j+1,m,dp);
                return dp[i][j]=op1;
            }else{
                return dp[i][j]=false;
            }
        }else{
            if(ch=='?')   
            {
                bool op1=isMatching(s,pat,i+1,n,j+1,m,dp);
                return dp[i][j]=op1;
            }else{
                bool op1=isMatching(s,pat,i,n,j+1,m,dp);
                if(op1)
                {
                    return dp[i][j]=op1;
                }
                bool op2=isMatching(s,pat,i+1,n,j+1,m,dp);
                if(op2)
                {
                    return dp[i][j]=op2;
                }
                bool op3=isMatching(s,pat,i+1,n,j,m,dp);
                return dp[i][j]=op3;
            }
        }
    }
    int wildCard(string pat,string s)
    {
        int n=s.size(),m=pat.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return isMatching(s,pat,0,n,0,m,dp);
    }
