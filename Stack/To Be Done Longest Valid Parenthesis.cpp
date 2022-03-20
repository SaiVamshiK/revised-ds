
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0

class Solution {
public:
    int longestValidParentheses(string s) { 
        int n=s.size();
        int *dp=new int[n];
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                dp[i]=0;
            }else{
                if(i==0)
                {
                    dp[i]=0;
                    continue;
                }
                if(s[i-1]=='(')
                {
                    if((i-2>=0))
                    {
                        dp[i]=2+dp[i-2];    
                    }else{
                        dp[i]=2;
                    }
                }else if(s[i-1]==')'){
                    int j=i-1;
                    j=j-dp[j];
                    if((j>=0)&&s[j]=='(')
                    {
                        int x=j-1;
                        if(x>=0)
                        {
                            dp[i]=2+dp[i-1]+dp[x];
                        }else{
                            dp[i]=2+dp[i-1];
                        }
                    }else{
                        dp[i]=0;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
