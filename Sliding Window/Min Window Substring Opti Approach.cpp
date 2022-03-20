class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> map;
        int n=s.size(),m=t.size();
        for(int i=0;i<m;i++)
        {
            map[t[i]]++;
        }
        int count=map.size();
        int i=0,j=0;
        string ret="";
        int ans=INT_MAX;
        while(j<n)
        {
            char ch=s[j];
            if(map.find(ch)!=map.end())
            {
                map[ch]--;
                if(map[ch]==0)
                {
                    count--;
                }
            }
            if(count!=0)
            {
                j++;
            }else{
                while(count==0)
                {
                    char ch=s[i];
                    if(ans>(j-i+1))
                    {
                        ans=j-i+1;
                        ret=s.substr(i,j-i+1);
                    }  
                    if(map.find(ch)!=map.end())
                    {
                        map[ch]++;
                        if(map[ch]==1)
                        {
                            count++;
                        }
                    }
                    i++;
                }
                j++;
            }
        }
        return ret;
    }
};
