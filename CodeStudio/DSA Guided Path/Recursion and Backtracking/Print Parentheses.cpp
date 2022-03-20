
Problem Statement
Given N pairs of parentheses, write a function to generate and print all combinations of well-formed parentheses. 
That is, you need to generate all possible valid sets of parentheses that can be formed with a given number of pairs.
Input Format:
The only line of input contains an integer ‘N’ representing the given number of parentheses.
Output Format:
The output contains all possible valid parentheses printed in different lines.

void func(int open,int close,int n,string &op)
{
    if(open==close&&(open==n))
    {
        cout<<op<<endl;
        return ;
    }
    if(open==n)
    {
        op.push_back('}');
        func(open,close+1,n,op);
        op.pop_back();
    }
    else if(open==close)
    {
        op.push_back('{');
        func(open+1,close,n,op);
        op.pop_back();
    }else{
        op.push_back('{');
        func(open+1,close,n,op);
        op.pop_back();
        op.push_back('}');
        func(open,close+1,n,op);
        op.pop_back();
    }
}
void printParantheses(int n) {
    string op="";
    func(0,0,n,op);
}
