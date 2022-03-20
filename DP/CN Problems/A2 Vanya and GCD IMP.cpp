Vanya has been studying all day long about sequences and other Complex Mathematical Terms. 
She thinks she has now become really good at it. So, her friend Vasya decides to test her knowledge and keeps the following challenge it front of her:
Vanya has been given an integer array A of size N. Now, she needs to find the number of increasing sub-sequences of 
this array with length =1 and GCD=1. A sub-sequence of an array is obtained by deleting some (or none) elements and 
maintaining the relative order of the rest of the elements. As the answer may be large, print it Modulo 109+7

**********************************		SEE THIS APPROACH		**********************************

#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int **dp=new int*[101];
    for(int i=0;i<=100;i++)
    {
		dp[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            dp[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        dp[a[i]][i]=1;
    }
    for(int i=1;i<n;i++)
    {
        int cur=a[i];
        for(int j=0;j<i;j++)
        {
            if(a[j]<cur)
            {
                for(int gcdVal=0;gcdVal<=100;gcdVal++)
                {
                    int cur_gcd=gcd(gcdVal,cur);
                    dp[cur_gcd][i]+=dp[gcdVal][j];
                    dp[cur_gcd][i]%=mod;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=dp[1][i];
        ans%=mod;
    }
    cout<<ans;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int **dp=new int*[101];
    for(int i=0;i<=100;i++)
    {
        dp[i]=new int[n];
        for(int j=0;j<n;j++)
        {
			dp[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        dp[a[i]][i]++;
    }
    for(int i=1;i<n;i++)
    {
		for(int j=0;j<i;j++)
        {
            if(a[i]>(a[j]))
            {
                for(int cur_gcd=0;cur_gcd<=100;cur_gcd++)
                {
                    if(dp[cur_gcd][j]!=0)
                    {
                        int g=gcd(cur_gcd,a[i]);
                        dp[g][i]=((dp[g][i]%MOD)+(dp[cur_gcd][j]%MOD))%MOD;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=((dp[1][i]%MOD)+(ans%MOD))%MOD;
    }
    cout<<ans<<endl;
    return 0;
}













