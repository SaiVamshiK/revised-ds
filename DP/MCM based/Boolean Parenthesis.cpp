Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

typedef pair<int,int> pi;
const int mod=1003;
pair<int,int> func(string s,int i,int j,vector<vector<pi>> &dp)
{
    if(i==j)
    {
        if(s[i]=='T')
        {
            return {1,0};
        }else{
            return {0,1};
        }
    }
    if(dp[i][j].first!=-1)
    {
        return dp[i][j];
    }
    pair<int,int> ans={0,0};
    for(int k=i;k<=(j-2);k++)
    {
        pair<int,int> left;
        if(dp[i][k].first==-1)
        {
            left=func(s,i,k,dp);
            dp[i][k]=left;
        }else{
            left=dp[i][k];
        }
        pair<int,int> right;
        if(dp[k+2][j].first==-1)
        {
            right=func(s,k+2,j,dp);
            dp[k+2][j]=right;
        }else{
            right=dp[k+2][j];
        }
        char op=s[k+1];
        int trueWays=0,falseWays=0;
        if(op=='|')
        {
            trueWays+=(left.first*right.first);
            trueWays+=(left.first*right.second);
            trueWays+=(left.second*right.first);
            falseWays+=(left.second*right.second);
        }else if(op=='&')
        {
            trueWays+=(left.first*right.first);
            falseWays+=(left.first*right.second);
            falseWays+=(left.second*right.first);
            falseWays+=(left.second*right.second);
        }else{
            trueWays+=(left.first*right.second);
            trueWays+=(left.second*right.first);
            falseWays+=(left.first*right.first);
            falseWays+=(left.second*right.second);
        }
        ans.first+=trueWays;
        ans.first%=mod;
        ans.second+=falseWays;
        ans.second%=mod;
    }
    return dp[i][j]=ans;
}
int Solution::cnttrue(string s) {
    int n=s.size();
    vector<vector<pi>> dp(n+1,vector<pi>(n+1,{-1,-1}));
    return func(s,0,n-1,dp).first%mod;
}

