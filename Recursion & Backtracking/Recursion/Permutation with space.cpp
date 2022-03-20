Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. 
The output should be printed in sorted increasing order of strings

Example 1:

Input:
S = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".

public:
    void func(string &inp,int i,int n,string op,vector<string> &ans)
    {
        if(i==(n-1))
        {
            op.push_back(inp[i]);
            ans.push_back(op);
            return ;
        }
        op.push_back(inp[i]);
        func(inp,i+1,n,op,ans);
        op.push_back(' ');
        func(inp,i+1,n,op,ans);
    }
    vector<string> permutation(string s){
        int n=s.size();
        string op="";
        vector<string> ans;
        func(s,0,n,op,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
