Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]

class Solution {
public:
    bool isPalin(string s)
    {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void func(vector<string> &op,string s,vector<vector<string>> &ans)
    {
        int n=s.size();
        for(int i=0;i<(n-1);i++)
        {
            string left=s.substr(0,i+1);
            string right=s.substr(i+1,n-i-1);
            if(isPalin(left))
            {
                op.push_back(left);
                if(isPalin(right))
                {
                    op.push_back(right);
                    ans.push_back(op);
                    op.pop_back();
                }
                func(op,right,ans);
                op.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> op;
        func(op,s,ans);
        if(isPalin(s))
        {
            vector<string> x;
            x.push_back(s);
            ans.push_back(x);
        }
        return ans;
    }
};





















