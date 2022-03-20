
Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. 
Each dictionary word can be used more than once. Return all such possible sentences.

Follow examples for better understanding.

Example 1:

Input: s = "catsanddog", n = 5 
dict = {"cats", "cat", "and", "sand", "dog"}
Output: (cats and dog)(cat sand dog)
Explanation: All the words in the given 
sentences are present in the dictionary.
Example 2:

Input: s = "catsandog", n = 5
dict = {"cats", "cat", "and", "sand", "dog"}
Output: Empty
Explanation: There is no possible breaking 
of the string s where all the words are present 
in dict.

class Solution{
public:
    bool isPresent(string s,vector<string>& dict)
    {
        for(int i=0;i<(dict.size());i++)
        {
            if(s==dict[i])
            {
                return true;
            }
        }
        return false;
    }
    void func(string &inp,vector<string> &op,vector<string>& dict,vector<string > &ans)
    {
        if(inp.empty())
        {
            string temp="";
            for(int i=0;i<((op.size())-1);i++)
            {
                temp+=op[i];
                temp+=" ";
            }
            temp+=op[(op.size())-1];
            ans.push_back(temp);
            return ;
        }
        int n=inp.size();
        for(int i=0;i<n;i++)
        {
            string left=inp.substr(0,i+1);
            string right=inp.substr(i+1,n-i-1);
            if(isPresent(left,dict))
            {
                op.push_back(left);
                func(right,op,dict,ans);
                op.pop_back();
            }
        }
    }
    vector<string> wordBreak(int size, vector<string>& dict, string s)
    {
        int n=s.size();
        vector<string> op;
        vector<string > ans;
        func(s,op,dict,ans);
        return ans;
    }
};

