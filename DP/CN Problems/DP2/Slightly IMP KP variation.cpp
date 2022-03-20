You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. 
The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not 
necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.

*********************************************	SEE THIS APPROACH		*********************************************

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
// {budget left,happy}
pi func(ll *a,ll *val,ll n,ll sum,vector<vector<pi>> &dp)
{
    if(sum==0||(n==0))
    {
        return {0,0};
    }
    if(dp[n][sum].first!=-1&&(dp[n][sum].second!=-1))
    {
        return dp[n][sum];
    }
    if(a[n-1]<=sum)
    {
  		pi op1=func(a,val,n-1,sum-a[n-1],dp);
        pi op2=func(a,val,n-1,sum,dp);
        ll happy1=op1.second+val[n-1];
        ll happy2=op2.second;
        ll spent1=op1.first+a[n-1];
        ll spent2=op2.first;
        if(happy1>happy2)
        {
            pi ans;
            ans.first=op1.first+a[n-1];
            ans.second=happy1;
            return dp[n][sum]=ans;
        }else if(happy2>happy1){
            pi ans;
            ans.first=op2.first;
            ans.second=happy2;
            return dp[n][sum]=ans;
        }else{
            if(spent1>spent2)
            {
                pi ans;
                ans.first=op2.first;
                ans.second=happy2;
                return dp[n][sum]=ans;
            }
            else{
                pi ans;
                ans.first=op1.first+a[n-1];
                ans.second=happy1;
                return dp[n][sum]=ans;
            }
        }
    }else{
        pi op=func(a,val,n-1,sum,dp);
        return dp[n][sum]=op;
    }
}
int main()
{
    ll sum,n;
    cin>>sum>>n;
    while(sum!=0&&(n!=0))
    {
        ll *a=new ll[n];
        ll *val=new ll[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i]>>val[i];
        }
        vector<vector<pi>> dp(n+1,vector<pi>(sum+1,{-1,-1}));
        pi ans=func(a,val,n,sum,dp);
        cout<<ans.first<<' '<<ans.second<<endl;
        cin>>sum>>n;
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
typedef pair<long,long> pi;

// {a,cost}
pi func(long *a,long *val,long n,long sum,pi **dp)
{
    if(sum==0||(n==0))
    {
        return {0,0};
    }
    if(dp[n][sum].first!=-1&&(dp[n][sum].second!=-1))
    {
        return dp[n][sum];
    }
    if(a[n-1]<=sum)
    {
        pi op1=func(a,val,n-1,sum-a[n-1],dp);
        pi op2=func(a,val,n-1,sum,dp);
        long cost1=op1.second+val[n-1],cost2=op2.second;
        long a1=op1.first+a[n-1];
        long a2=op2.first;
        if(cost1>cost2)
        {
            return dp[n][sum]={a1,cost1};
        }else if(cost2>cost1){
            return dp[n][sum]={a2,cost2};
        }else{
            if(a1<a2)
            {
                return dp[n][sum]={a1,cost1};
            }
            return dp[n][sum]={a2,cost2};
        }
    }else{
        pi op=func(a,val,n-1,sum,dp);
        long cost=op.second;
        long a=op.first;
        return dp[n][sum]={a,cost};
    }
}
int main()
{
    long sum,n;
    cin>>sum>>n;
    while(sum!=0&&(n!=0))
    {
        long *a=new long[n];
        long *val=new long[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>val[i];
        }
        pi **dp=new pi*[n+1];
        for(long i=0;i<=n;i++)
        {
            dp[i]=new pi[sum+1];
            for(long j=0;j<=sum;j++)
            {
                dp[i][j].first=-1;
                dp[i][j].second=-1;
            }
        }
        pi ans=func(a,val,n,sum,dp);
        cout<<ans.first<<' '<<ans.second<<endl;
        cin>>sum>>n;
    }
    return 0;
}











