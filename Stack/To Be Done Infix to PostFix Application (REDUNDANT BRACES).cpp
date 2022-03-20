
Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.

Chech whether A has redundant braces or not.

Return 1 if A has redundant braces, else return 0.

Note: A will be always a valid expression.



Input Format

The only argument given is string A.
Output Format

Return 1 if string has redundant braces, else return 0.
For Example

Input 1:
    A = "((a + b))"
Output 1:
    1
    Explanation 1:
        ((a + b)) has redundant braces so answer will be 1.

bool isAlphabet(char ch)
{
    if(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z')))
    {
        return true;
    }
    return false;
}
bool isOperator(char ch)
{
    if(ch=='*'||(ch=='+')||(ch=='/')||(ch=='-'))
    {
        return true;
    }
    return false;
}
int precedence(char ch)
{
    if(ch=='+'||(ch=='-'))
    {
        return 1;
    }
    return 2;
}
int Solution::braces(string s) {
    int n=s.size();
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        char ch=s[i];
        if(isAlphabet(ch))
        {
            // include in answer
        }else if(isOperator(ch))
        {
            while((!st.empty())&&(st.top()!='(')&&(precedence(st.top())>=precedence(ch)))
            {
                st.pop();
            }
            st.push(ch);
        }else if(ch=='(')
        {
            st.push(ch);
        }else if(ch==')')
        {
            if(st.top()=='(')
            {
                return 1;
            }
            while((!st.empty())&&(st.top()!='('))
            {
                st.pop();
            }
            st.pop();
        }
    }
    return 0;
}

