int func(string s1,string s2,string s3,int x,int y,int z,vector<vector<vector<int>>> &dp)
{
    if(x==0||(y==0)||(z==0))
    {
        return 0;
    }
    if(dp[x][y][z]!=-1)
    {
        return dp[x][y][z];
    }
    if(s1[x-1]==s2[y-1]&&(s2[y-1]==s3[z-1]))
    {
        return dp[x][y][z]=1+func(s1,s2,s3,x-1,y-1,z-1,dp);
    }else{
        int op1;
        if(dp[x-1][y][z]!=-1)
        {
            op1=dp[x-1][y][z];
        }else{
            op1=func(s1,s2,s3,x-1,y,z,dp);
        }
        int op2;
        if(dp[x][y-1][z]!=-1)
        {
            op2=dp[x][y-1][z];
        }else{
            op2=func(s1,s2,s3,x,y-1,z,dp);
        }
        int op3;
        if(dp[x][y][z-1]!=-1)
        {
            op3=dp[x][y][z-1];
        }else{
            op3=func(s1,s2,s3,x,y,z-1,dp);
        }
        return dp[x][y][z]=max(op1,max(op2,op3));
    }
}

int LCSof3 (string s1, string s2, string s3, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
    int ans=func(s1,s2,s3,n1,n2,n3,dp);
    return ans;
}
