
Mike is a stock trader and makes a profit by buying and selling stocks. He buys a stock at a lower price and
sells it at a higher price to book a profit. He has come to know the stock prices of a particular stock for n 
upcoming days in future and wants to calculate the maximum profit by doing the right transactions
(single transaction = buying + selling). Can you help him maximize his profit?
Note: A transaction starts after the previous transaction has ended. Two transactions can't overlap or run in parallel.
The stock prices are given in the form of an array A for n days.
Given the stock prices and a positive integer k, find and print the maximum profit Mike can make in at most k transactions.

#include <bits/stdc++.h>
using namespace std;
int func(int *a,int n,int k,bool started,vector<vector<vector<int>>> &dp)
{
    if(k==0)
    {
        return 0;
    }
    if(n==0)
    {
        if(!started)
        {
            return 0;
        }
        return INT_MIN;
    }
    if(dp[n][k][started]!=-1)
    {
        return dp[n][k][started];
    }
    if(!started)
    {
        int op1=func(a,n-1,k,true,dp);
        if(op1!=INT_MIN)
        {
            op1=op1-a[n-1];
        }else{
            op1=INT_MIN;
        }
        int op2=func(a,n-1,k,false,dp);
        return dp[n][k][started]=max(op1,op2);
    }else{
        int op1=func(a,n-1,k-1,false,dp);
        if(op1!=INT_MIN)
        {
            op1+=a[n-1];
        }else{
            op1=INT_MIN;
        }
        int op2=func(a,n-1,k,true,dp);
        return dp[n][k][started]=max(op1,op2);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int n;
        cin>>n;
        int *a=new int[n];
        for(int i=n-1;i>=0;i--)
        {
            cin>>a[i];
        }
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        cout<<func(a,n,k,false,dp)<<endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int func(int *a,int n,int k,int start,vector<vector<vector<int>>> &dp)
{
    if(k==0&&(start==0))
    {
        return 0;
    }
    if(n==0&&(start==0))
    {
        return 0;
    }
    if(n==0&&(start==1))
    {
        return 0;
    }
    if(dp[n][k][start]!=-1)
    {
        return dp[n][k][start];
    }
    if(!start)
    {
        return dp[n][k][start]=max(func(a,n-1,k,1,dp)-a[n-1],func(a,n-1,k,0,dp));
    }else{
        return dp[n][k][start]=max(a[n-1]+func(a,n-1,k-1,0,dp),func(a,n-1,k,1,dp));
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int n;
        cin>>n;
        int *a=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        reverse(a,a+n);
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        int ans=func(a,n,k,0,dp);
        cout<<ans<<endl;
    }
    return 0;
}























