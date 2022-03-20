
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.



Input Format

The only argument given is character array A.
Output Format

Return the value of arithmetic expression formed using reverse Polish Notation.
For Example

Input 1:
    A =   ["2", "1", "+", "3", "*"]
Output 1:
    9
    


#include<bits/stdc++.h>
using namespace std;
bool OperatorFunc(string str)
{
    if(str.size()==1)
    { 
        if(str[0]=='+'||(str[0]=='-')||(str[0]=='*')||(str[0]=='/'))
        {
            return true;
        }
        return false;
    }else{
        return false;
    }
}
int Solution::evalRPN(vector<string> &a) {
    if(a.size()==1)
    {
        return stoi(a[0]);
    }
    stack<int> st;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        string str=a[i];
        if(!OperatorFunc(str))
        {
            int val=stoi(str);
            st.push(val);
        }else{
            int one=st.top();
            st.pop();
            int two=st.top();
            st.pop();
            char ch=str[0];
            if(ch=='-')
            {
                st.push(two-one);
            }else if(ch=='+')
            {
                st.push(two+one);
            }else if(ch=='/')
            {
                st.push(two/one);
            }else{
                st.push(two*one);
            }
        }
    }
    return st.top();
}

