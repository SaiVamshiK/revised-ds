Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.

 

Example 1:

Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"

string findSubString(string s)
{
    int n=s.size();
    unordered_map<char,int> mp;
    for(int i=0;i<n;i++)
    {
        if(mp.find(s[i])==mp.end())
        {
            mp[s[i]]++;
        }
    }
    int count=mp.size();
    int i=0,j=0;
    int potential_ans=INT_MAX;
    string potential_str;
    bool done=false;
    while(j<n)
    {
        if(done==false)
        {
            char cur_ch=s[j];
            if(mp.find(cur_ch)!=mp.end())
            {
                mp[cur_ch]--;
                if(mp[cur_ch]==0)
                {
                    count--;
                }
            }
        }
        if(count!=0)
        {
            j++;
            done=false;
        }else{
            if((potential_ans)>(j-i+1))
            {
                potential_ans=(j-i+1);
                potential_str=s.substr(i,potential_ans);
            }
            char cur_i=s[i];
            if(mp.find(cur_i)!=mp.end())
            {
                mp[cur_i]++;
                if(mp[cur_i]==1)
                {
                    count++;
                }
            }
            i++;
            done=true;
        }
    }
    return potential_str;
}

