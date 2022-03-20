
Given a string A containing just the characters ’(‘ and ’)’.

Find the length of the longest valid (well-formed) parentheses substring.



Input Format:

The only argument given is string A.
Output Format:

Return the length of the longest valid (well-formed) parentheses substring.

int Solution::longestValidParentheses(string s) {
    int n=s.size();
    int *dp=new int[n];
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='(')
        {
            dp[i]=0;
        }else if(s[i]==')'){
            if(s[i-1]=='(')
            {
                if((i-2)>=0)
                {
                    dp[i]=2+dp[i-2];   
                }else{
                    dp[i]=2;
                }
            }else{
                int match=i-dp[i-1]-1;
                if((match>=0)&&s[match]=='(')
                {
                    dp[i]=dp[i-1]+2;
                    if((match-1)>=0)
                    {
                        dp[i]+=dp[match-1];
                    }
                }else{
                    dp[i]=0;
                }
            }
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dp[i]);
    }
    return ans;
}

