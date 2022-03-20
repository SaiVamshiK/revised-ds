Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of A = “great”:


    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”

bool func(string s1,string s2,unordered_map<string, bool> &dp)
{
    int n=s1.size();
    if(n==1)
    {
        return s1[0]==s2[0];
    }
    if(dp.find(s1+' '+s2)!=dp.end())
    {
        return dp[s1+' '+s2];
    }
    for(int k=0;k<(n-1);k++)
    {
        // i to k , k+1 to j
        if(((func(s1.substr(0,k+1),s2.substr(0,k+1),dp))&&
        (func(s1.substr(k+1,n-k-1),s2.substr(k+1,n-k-1),dp)))||
        ((func(s1.substr(0,k+1),s2.substr(n-k-1,k+1),dp))&&
        (func(s1.substr(k+1,n-k-1),s2.substr(0,n-k-1),dp))))
        {
            dp.insert({s1+' '+s2,true});
            return true;
        }
    }
    dp.insert({s1+' '+s2,false});
    return false;
}
int Solution::isScramble(const string s1, const string s2) {
    unordered_map<string, bool> dp;
    int n=s1.size(),m=s2.size();
    if(n!=m)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }
    return func(s1,s2,dp);
}

*************************************	SEE THIS APPROACH		*************************************

bool isEqual(string s1,string s2)
{
    for(int i=0;i<(s1.size());i++)
    {
        if(s1[i]!=s2[i])
        {
            return false;
        }
    }
    return true;
}
bool func(string s1,string s2,unordered_map<string,bool> &mp)
{
    int n=s1.size();
    int i=0,j=n-1;
    if(isEqual(s1.substr(i,j-i+1),s2.substr(i,j-i+1)))
    {
        return true;
    }
    bool ans=false;
    string cur=s1+"."+s2;
    if(mp.find(cur)!=mp.end())
    {
        return mp[cur];
    }
    for(int k=i;k<=(j-1);k++)
    {
        ans=ans||
            (func(s1.substr(i,k-i+1),s2.substr(i,k-i+1),mp)&&
                func(s1.substr(k+1,j-k),s2.substr(k+1,j-k),mp));
        if(ans)
        {
            return mp[cur]=ans;
        }
        int x=n-k-1;
        ans=ans||
            (func(s1.substr(i,k-i+1),s2.substr(x,j-x+1),mp)&&
                func(s1.substr(k+1,j-k),s2.substr(i,x-i),mp));
        if(ans)
        {
            return mp[cur]=ans;
        }
        
    }
    return mp[cur]=false;
}
int Solution::isScramble(const string s1, const string s2) {
    int n=s1.size(),m=s2.size();
    if(n!=m)
    {
        return false;
    }
    if(n==0||(n==1))
    {
        return true;
    }
    unordered_map<string,bool> mp;
    return func(s1,s2,mp);
}


