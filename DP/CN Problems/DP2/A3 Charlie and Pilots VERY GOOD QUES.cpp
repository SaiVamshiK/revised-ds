
Charlie acquired airline transport company and to stay in business he needs to lower the expenses 
by any means possible. There are N pilots working for his company (N is even) and N/2 plane crews 
needs to be made. A plane crew consists of two pilots - a captain and his assistant. 
A captain must be older than his assistant. Each pilot has a contract granting him two 
possible salaries - one as a captain and the other as an assistant. 
A captain's salary is larger than assistant's for the same pilot. 
However, it is possible that an assistant has larger salary than his captain. 
Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' 
salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int func(pi *a,int n,int assitants,int captains,int req,vector<vector<int>> &dp)
{
    if(assitants==req&&(captains==req))
    {
        return 0;
    }
    if(n==0)
    {
        return INT_MAX;
    }
    if(dp[n][assitants]!=-1)
    {
        return dp[n][assitants];
    }
    if(assitants==captains)
    {
        int op1=func(a,n-1,assitants+1,captains,req,dp);
        if(op1!=INT_MAX)
        {
        	op1+=a[n-1].second;    
        }
        return dp[n][assitants]=op1;
    }else{
        // a > c
        if(assitants==(req))
        {
            int op1=func(a,n-1,assitants,captains+1,req,dp);
            if(op1!=INT_MAX)
            {
            	op1+=a[n-1].first;    
            }
            return dp[n][assitants]=op1;
        }else{
            int op1=func(a,n-1,assitants+1,captains,req,dp);
            if(op1!=INT_MAX)
            {
            	op1+=a[n-1].second;    
            }
            int op2=func(a,n-1,assitants,captains+1,req,dp);
            if(op2!=INT_MAX)
            {
            	op2+=a[n-1].first;    
            }
            return dp[n][assitants]=min(op1,op2);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    pi *a=new pi[n];
    // {cap,assist}
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    reverse(a,a+n);
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    cout<<func(a,n,0,0,n/2,dp)<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int func(int *captain,int *assistant,int a,int c,int i,int n,vector<vector<int>> &dp)
{
    if(a==c&&(c==(n/2))&&(i==n))
    {
        return 0;
    }
    if(i==n)
    {
        return INT_MAX;
    }
    if(dp[a][i]!=-1)
    {
        return dp[a][i];
    }
    if(a==c)
    {
        int call1=func(captain,assistant,a+1,c,i+1,n,dp);
        if(call1==INT_MAX)
        {
            return dp[a][i]=INT_MAX;
        }
        return dp[a][i]=assistant[i]+(call1);
    }else if(a>c)
    {
        int call1=func(captain,assistant,a,c+1,i+1,n,dp);
        int call2=func(captain,assistant,a+1,c,i+1,n,dp);
        if(call1==INT_MAX&&(call2!=INT_MAX))
        {
            return dp[a][i]=call2+assistant[i];
        }
        if(call1!=INT_MAX&&(call2==INT_MAX))
        {
            return dp[a][i]=call1+captain[i];
        }
        if(call1==INT_MAX&&(call2==INT_MAX))
        {
            return dp[a][i]=INT_MAX;
        }
        return dp[a][i]=min(captain[i]+call1,
                  assistant[i]+call2);
    }
}
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    int *c=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>c[i]>>a[i];
    }
    //vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    int ans=func(c,a,0,0,0,n,dp);
    cout<<ans;
    return 0;
}



















