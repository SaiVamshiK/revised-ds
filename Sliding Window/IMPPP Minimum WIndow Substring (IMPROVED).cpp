class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp_t;
        int n=s.size(),m=t.size();
        for(int i=0;i<m;i++)
        {
            mp_t[t[i]]++;
        }
        int count=mp_t.size();
        int i=0,j=0;
        int potential_ans=INT_MAX;
        string potential_str;
        bool done=false;
        while(j<n)
        {
            if(done==false)
            {
                char cur_ch=s[j];
                int cur_ch_freq;
                if(mp_t.find(cur_ch)!=mp_t.end())
                {
                    mp_t[cur_ch]--;
                    if(mp_t[cur_ch]==0)
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
                if(mp_t.find(cur_i)!=mp_t.end())
                {
                    mp_t[cur_i]++;
                    if(mp_t[cur_i]==1)
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
};













