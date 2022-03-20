Given a string, count the number of distinct subsequences of it ( including empty subsequence ). \
For the uninformed, A subsequence of a string is a new string which is formed from the original string by 
deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.

const int mod=1e9+7;
typedef long long ll;
class Solution {
public:
    ll func(string s,ll n)
    {
        ll *dp=new ll[n+1];
        dp[0]=1;
        unordered_map<char,int> mp;
        for(ll i=1;i<=n;i++)
        {
            char ch=s[i-1];
            dp[i]=((2%mod)*(dp[i-1]%mod))%mod;
            if(mp.find(ch)!=mp.end())
            {
                int j=mp[ch];
                dp[i]=((dp[i]%mod)-(dp[j-1]%mod)+mod)%mod;
            }
            mp[ch]=i;
        }
        return dp[n]%mod;
    }
    int distinctSubseqII(string s) {
        ll n=s.size();
        return func(s,n)-1;
    }
};


#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
typedef long long int ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll n=s.size();
        ll *dp=new ll[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            char cur_ch=s[i-1];
            bool done=false;
            ll sum=0;
            for(int j=i-1;j>=1;j--)
            {
                sum=((sum%MOD)+(dp[j]%MOD))%MOD;
                if(s[j-1]==cur_ch)
                {
                    done=true;
                    break;
                }
            }
            if(!done)
            {
                sum=((sum%MOD)+(dp[0]%MOD))%MOD;
            }
            dp[i]=sum;
        }
        ll ans=0;
        for(int i=0;i<=n;i++)
        {
            ans=((ans%MOD)+(dp[i]%MOD))%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}























