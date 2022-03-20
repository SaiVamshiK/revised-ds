
Problem Statement
You have been given an integer K.
Your task is to generate all binary strings of length K such that there are no consecutive 1s in the string. This means that the binary string should not contain any instance of 1’s coming one after another.
A binary string is that string which contains only ‘0’ and ‘1’.

void func(int i,int n,string &op,vector<string> &ans,char prev)
{
    if(i==n)
    {
        ans.push_back(op);
        return ;
    }
    if(i==0)
    {
        op.push_back('0');
        func(i+1,n,op,ans,'0');
        op.pop_back();
        op.push_back('1');
        func(i+1,n,op,ans,'1');
        op.pop_back();
    }else{
        if(prev=='0')
        {
            op.push_back('0');
            func(i+1,n,op,ans,'0');
            op.pop_back();
            op.push_back('1');
            func(i+1,n,op,ans,'1');
            op.pop_back();
        }else{
            op.push_back('0');
            func(i+1,n,op,ans,'0');
            op.pop_back();
        }
    }
}
vector<string> generateString(int n) {
    string op="";
    vector<string> ans;
    char prev='0';
    func(0,n,op,ans,prev);
    return ans;
}


