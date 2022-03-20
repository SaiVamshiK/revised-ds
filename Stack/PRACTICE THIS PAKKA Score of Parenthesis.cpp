
Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(-1);
            }else{
                int topElem=st.top();
                if(topElem==-1)
                {
                    st.pop();
                    st.push(1);
                }else{
                    int sum=0;
                    while(st.top()!=-1)
                    {
                        sum=sum+st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*sum);
                }
            }
        }
        int sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};
