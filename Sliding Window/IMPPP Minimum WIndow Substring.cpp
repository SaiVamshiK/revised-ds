class Solution {
public:
    bool isSufficient(unordered_map<char,int> &mp_t,unordered_map<char,int> &mp_s)
    {
        for(auto it=mp_t.begin();it!=mp_t.end();it++)
        {
            char cur_ch=(it->first);
            int cur_ch_freq=(it->second);
            if(mp_s.find(cur_ch)==mp_s.end())
            {
                return false;
            }else{
                auto itr=mp_s.find(cur_ch);
                if((itr->second)<cur_ch_freq)
                {
                    return false;
                }
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        unordered_map<char,int> mp_t;
        for(int i=0;i<m;i++)
        {
            mp_t[t[i]]++;
        }
        unordered_map<char,int> mp_s;
        int i=0,j=0;
        int potential_ans=INT_MAX;
        string potential_string="";
        bool done=false;
        while(j<n)
        {
            if(!done)
            {
                mp_s[s[j]]++;
                done=false;
            }
            if(isSufficient(mp_t,mp_s))
            {
                if(potential_ans>(j-i+1))
                {
                    potential_ans=(j-i+1);
                    potential_string=s.substr(i,(j-i+1));
                }
                char cur_ch=s[i];
                auto itr=mp_s.find(cur_ch);
                int cur_ch_freq=itr->second;
                cur_ch_freq--;
                mp_s.erase(itr);
                if(cur_ch_freq!=0)
                {
                    mp_s.insert({cur_ch,cur_ch_freq});
                }
                i++;
                done=true;
            }else{
                j++;
                if(done)
                {
                    done=false;
                }
            }
        }
        return potential_string;
    }
};













