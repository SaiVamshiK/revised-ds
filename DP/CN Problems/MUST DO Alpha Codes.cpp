
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
Input
Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.
Output
For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"
Sample Input:
25114
1111111111
3333333333
0
Sample Output:
6
89
1


***********************************		SEE THIS APPROACH	***********************************

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll func(string s,ll n,bool &done,vector<ll> &dp)
{
    if(n==1||(n==0))
    {
        return dp[n]=1;
    }
    if(done)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
	ll last_digit=s[n-1]-'0';
    if(last_digit!=0)
    {
        ll second_last=s[n-2]-'0';
        if(second_last!=0)
        {
            ll op1;
            if(dp[n-1]!=-1)
            {
                op1=dp[n-1];
            }else{
                op1=func(s,n-1,done,dp);
            }
            ll val=last_digit+((second_last)*(10));
            if(val>=1&&(val<=26))
            {
                ll op2;
                if(dp[n-2]!=-1)
                {
                    op2=dp[n-2];
                }else{
                    op2=func(s,n-2,done,dp);
                }
                return dp[n]=(((op1%mod)+(op2%mod))%mod);
            }else{
                return dp[n]=(op1%mod);
            }
        }else{
            ll op1;
            if(dp[n-1]!=-1)
            {
                op1=dp[n-1];
            }else{
                op1=func(s,n-1,done,dp);
            }
            return dp[n]=(op1%mod);
        }
    }else{
        ll second_last=s[n-2]-'0';
        ll val=(second_last*10)+(last_digit);
        if(val>=1&&(val<=26))
        {
            ll op1;
            if(dp[n-2]!=-1)
            {
                op1=dp[n-2];
            }else{
                op1=func(s,n-2,done,dp);
            }
            return dp[n]=(op1%mod);
        }else{
            done=true;
            return dp[n]=0;
        }
    }
}
int main()
{
    string s;
    cin>>s;
    while(s[0]!='0')
    {
        ll n=s.size();
        bool done=false;
        vector<ll> dp(n+1,-1);
        ll ans=func(s,n,done,dp);
        if(done)
        {
            cout<<0<<endl;
            cin>>s;
            continue; 
        }
        cout<<ans<<endl;
        cin>>s;
    }
    return 0;
}





#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int func(string &s,int n,int *dp)
{
    if(n==0||(n==1))
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n]%MOD;
    }
    if(s[n-1]!='0')
    {
        int f1=func(s,n-1,dp);
        int val=((10*(s[n-2]-'0'))+(s[n-1]-'0'));
        if(val>=10&&(val<=26))
        {
            int f2=func(s,n-2,dp);
            return dp[n]=((f1%MOD)+(f2%MOD))%MOD;
        }
        return dp[n]=f1%MOD;
    }else{
        int val=((10*(s[n-2]-'0'))+(s[n-1]-'0'));
        if(val>=10&&(val<=26))
        {
            int t=func(s,n-2,dp);
            return dp[n]=t%MOD;
        }
        return dp[n]=0;
    }
}
int main()
{
    string s;
    cin>>s;
    while(s!="0")
    {
        int n=s.size();
        int *dp=new int[n+1];
        for(int i=0;i<=n;i++)
        {
			dp[i]=-1;
        }
        cout<<func(s,n,dp)<<endl;
        cin>>s;
    }
    return 0;
}














