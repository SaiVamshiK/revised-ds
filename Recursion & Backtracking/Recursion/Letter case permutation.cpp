
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

 

Example 1:

Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
class Solution {
public:
    char find(char ch)
    {
        if(ch>='a'&&(ch<='z'))
        {
            return ch-32;
        }
        return ch+32;
    }
    void func(string inp,int i,int n,string op,vector<string> &ans)
    {
        if(i==n)
        {
            ans.push_back(op);
            return ;
        }
        char ch=inp[i];
        if((ch>='a'&&(ch<='z'))||((ch>='A'&&(ch<='Z'))))
        {
            char comp=find(ch);
            op.push_back(ch);
            func(inp,i+1,n,op,ans);
            op.pop_back();
            op.push_back(comp);
            func(inp,i+1,n,op,ans);
        }else{
            op.push_back(ch);
            func(inp,i+1,n,op,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        string op="";
        vector<string> ans;
        func(s,0,n,op,ans);
        return ans;
    }
};
