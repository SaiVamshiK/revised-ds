
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.

class Solution {
public:
    int func(int i,int n,int copy,vector<vector<int>> &dp)
    {
        if(i>n)
        {
            return INT_MIN;
        }
        if(i==n)
        {
            return 0;
        }
        if(dp[i][copy]!=-1)
        {
            return dp[n][copy];
        }
        if(copy!=0)
        {
            // paste or copy
            int op1=func(i+copy,n,copy,dp);
            int op2=INT_MIN;
            if(copy!=i)
            {
               op2=func(i,n,i,dp); 
            }
            if(op1!=INT_MIN&&(op2!=INT_MIN))
            {
                return dp[n][copy]=1+min(op1,op2);
            }else if((op1!=INT_MIN))
            {
                return dp[n][copy]=1+op1;
            }else if(op2!=INT_MIN)
            {
                return dp[n][copy]=1+op2;
            }else {
                return dp[n][copy]=INT_MIN;
            }
        }else{
            // copy 
            return dp[n][copy]=1+func(i,n,i,dp);
        }
    }
    int minSteps(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return func(1,n,0,dp);
    }
};
















