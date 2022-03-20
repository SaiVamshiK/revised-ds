
Given a string A consisting only of '(' and ')'.

You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.



int Solution::solve(string s) {
    int n=s.size();
    stack<char> st;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
        }else{
            if(st.empty())
            {
                return false;
            }
            st.pop();
        }
    }
    if(st.empty())
    {
        return true;
    }
    return false;
}
 
