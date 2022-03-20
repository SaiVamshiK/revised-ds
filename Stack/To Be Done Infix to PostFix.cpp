
Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
​Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 
Example 1:

Input: str = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-
Explanation:
After converting the infix expression 
into postfix expression, the resultant 
expression will be abcd^e-fgh*+^*+i-

class Solution
{
    public:
    bool isAlphabet(char ch)
    {
        if(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z')))
        {
            return true;
        }
        return false;
    }
    int findPrecedence(char ch)
    {
        if(ch=='+'||(ch=='-'))
        {
            return 0;
        }
        else if(ch=='*'||(ch=='/'))
        {
            return 1;
        }
        return 2;
    }
    //Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        stack<char> st;
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(isAlphabet(ch))
            {
                ans.push_back(ch);
            }else{
                if(ch!='('&&(ch!=')'))
                {
                    int curPrecedence=findPrecedence(ch);
    while((!st.empty())&&(st.top()!='(')&&(findPrecedence(st.top())>=curPrecedence))
                    {
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.push(ch);
                }else{
                    if(ch=='(')
                    {
                        st.push(ch);
                    }else{
                        while(!st.empty()&&(st.top()!='('))
                        {
                            ans.push_back(st.top());
                            st.pop();
                        }
                        st.pop();
                    }
                }
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
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
        if(ch=='/'||(ch=='*')||(ch=='+')||(ch=='-')||(ch=='^'))
        {
            return true;
        }
        return false;
    }
    int precedence(char ch)
    {
        if(ch=='-'||(ch=='+'))
        {
            return 0;
        }
        if(ch=='*'||(ch=='/'))
        {
            return 1;
        }
        return 2;
    }
    string infixToPostfix(string s)
    {
        string ans="";
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(isAlphabet(ch))
            {
                ans.push_back(ch);
            }else if(isOperator(ch))
            {
                while((!st.empty())&&(st.top()!='(')&&(precedence(st.top())>=precedence(ch)))
                {
                    char cur=st.top();
                    ans.push_back(cur);
                    st.pop();
                }
                st.push(ch);
            }else if(ch=='(')
            {
                st.push(ch);
            }else if(ch==')')
            {
                while((!st.empty())&&(st.top()!='('))
                {
                    char cur=st.top();
                    ans.push_back(cur);
                    st.pop();
                }
                st.pop();
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};


