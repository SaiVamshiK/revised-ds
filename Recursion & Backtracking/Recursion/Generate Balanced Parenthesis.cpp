Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

void func(string op,int open,int close,vector<string> &ans,int n)
{
    if(open==close)
    {
        if(open==n)
        {
            ans.push_back(op);
            return ;
        }else{
            op.push_back('(');
            func(op,open+1,close,ans,n);
        }
    }else if(open>close)
    {
        if(open!=n)
        {
            op.push_back('(');
            func(op,open+1,close,ans,n);
            op.pop_back();
            op.push_back(')');
            func(op,open,close+1,ans,n);
        }else{
            op.push_back(')');
            func(op,open,close+1,ans,n);
        }
        
    }
}
vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    string op="";
    func(op,0,0,ans,A);
    return ans;
}

