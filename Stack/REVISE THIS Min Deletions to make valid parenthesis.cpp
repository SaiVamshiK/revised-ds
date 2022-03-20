
Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the 
resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        int n=s.size();
        int op=0;
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(ch=='(')
            {
                op++;
                ans.push_back(ch);
            }else if(ch==')')
            {
                if(op!=0)
                {
                    op--;
                    ans.push_back(ch);
                }
            }
        }
        string ans1="";
        int q=ans.size(),cl=0;
        for(int i=q-1;i>=0;i--)
        {
            char ch=ans[i];
            if(ch==')')
            {
                cl++;
                ans1.push_back(ch);
            }else{
                if(cl!=0)
                {
                    cl--;
                    ans1.push_back(ch);
                }
            }
        }
        reverse(ans1.begin(),ans1.end());
        string ret="";
        int idx=0,m=ans1.size();
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(ch!='('&&(ch!=')'))
            {
                ret.push_back(ch);
            }else{
                if(idx==m)
                {
                    continue;
                }
                if(ans1[idx]==ch)
                {
                    ret.push_back(ch);
                    idx++;
                }
            }
        }
        return ret;
    }
};













class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        string ans="";
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                ans.push_back(s[i]);
            }else if(s[i]==')')
            {
                if(!st.empty())
                {
                    ans.push_back(s[i]);
                    st.pop();
                }
            }else{
                ans.push_back(s[i]);
            }
        }
        if(st.empty())
        {
            return ans;
        }
        while(!st.empty())
        {
            st.pop();
        }
        string res="";
        for(int i=(ans.size()-1);i>=0;i--)
        {
            if(ans[i]==')')
            {
                st.push(ans[i]);
                res.push_back(ans[i]);
            }else if(ans[i]=='(')
            {
                if(!st.empty())
                {
                    st.pop();
                    res.push_back(ans[i]);
                }
            }else{
                res.push_back(ans[i]);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};



