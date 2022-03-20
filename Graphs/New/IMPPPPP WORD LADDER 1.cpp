Given two words A and B, and a dictionary, C, 
find the length of shortest transformation sequence from A to B, such that:

You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

vector<string> func(string x,unordered_set<string> &st)
{
    vector<string> ans;
    for(int i=0;i<(x.size());i++)
    {
        char ch=x[i],replace;
        for(int j=0;j<26;j++)
        {
            replace='a'+j;
            if(ch!=replace)
            {
                x[i]=replace;
                if(st.find(x)!=st.end())
                {
                    ans.push_back(x);
                    st.erase(x);
                }
                x[i]=ch;
            }
        }
    }
    return ans;
}
int Solution::solve(string A, string B, vector<string> &C) {
    unordered_set<string> st;
    for(int i=0;i<(C.size());i++)
    {
        st.insert(C[i]);
    }
    queue<string> q;
    q.push(A);
    int ans=1;
    while(!q.empty())
    {
        int sz=q.size();
        ans++;
        for(int i=0;i<sz;i++)
        {
            string cur=q.front();
            q.pop();
            if(cur==B)
            {
                return ans;
            }
            vector<string> allStrings=func(cur,st);
            for(int i=0;i<(allStrings.size());i++)
            {
                q.push(allStrings[i]);
                string x=allStrings[i];
                for(int i=0;i<(x.size());i++)
                {
                    char ch=x[i],replace;
                    for(int j=0;j<26;j++)
                    {
                        replace='a'+j;
                        if(ch!=replace)
                        {
                            x[i]=replace;
                            if(x==B)
                            {
                                return ans+1;
                            }
                            x[i]=ch;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

