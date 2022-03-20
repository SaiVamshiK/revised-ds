bool func(string s1,string s2,unordered_map<string,bool> &mp)
{
    if(s1==s2)
    {
        return true;
    }
    int n=s1.size();
    int j=n-1;
    if(mp.find(s1+' '+s2)!=mp.end())
    {
        return mp[s1+' '+s2];
    }
    for(int k=0;k<(n-1);k++)
    {
        bool op1;
op1=(func(s1.substr(0,k+1),s2.substr(0,k+1),mp)&&func(s1.substr(k+1,j-k),s2.substr(k+1,j-k),mp)
|| func(s1.substr(0,k+1),s2.substr(j-k,k+1),mp)&&func(s1.substr(k+1,j-k),s2.substr(0,j-k),mp)
    );
        if(op1)
        {
            return mp[s1+' '+s2]=true;
        }
    }
    return mp[s1+' '+s2]=false;
}
int Solution::isScramble(const string s1, const string s2) {
    int n=s1.size(),m=s2.size();
    if(n!=m)
    {
        return 0;
    }
    if(n==0&&(m==0))
    {
        return 1;
    }
    unordered_map<string,bool> mp;
    return func(s1,s2,mp);
}

