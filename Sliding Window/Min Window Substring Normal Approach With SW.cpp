class Solution {
public:
    bool isPossible(unordered_map<char,int> map,unordered_map<char,int> temp)
    {
        for(auto it=temp.begin();it!=temp.end();it++)
        {
            char ch=it->first;
            int freq=it->second;
            auto itr=map.find(ch);
            if(itr==map.end())
            {
                return false;
            }
            if((itr->second)<freq)
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        unordered_map<char,int> temp;
        for(int i=0;i<m;i++)
        {
            temp[t[i]]++;
        }
        unordered_map<char,int> map;
        int i=0,j=0;
        int ans=INT_MAX;
        string ret="";
        while(j<n)
        {
            map[s[j]]++;
            if(!isPossible(map,temp))
            {
                j++;
            }else{
                while(isPossible(map,temp))
                {
                    if(ans>(j-i+1))
                    {
                        ans=min(ans,j-i+1);
                        ret=s.substr(i,(j-i+1));
                    }
                    map[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return ret;
    }
};
