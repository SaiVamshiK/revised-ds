
The fibonacci sequence is defined by the following relation:
 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M (N <= M), 
you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.


#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
void multiply(ll** &a,ll **b)
{
    ll **res=new ll*[2];
    for(ll i=0;i<2;i++)
    {
        res[i]=new ll[2];
        for(ll j=0;j<2;j++)
        {
            res[i][j]=0;
        }
    }
    for(ll i=0;i<2;i++)
    {
        for(ll j=0;j<2;j++)
        {
            for(ll k=0;k<2;k++)
            {
                res[i][j]=((((a[i][k]%mod)*(b[k][j]%mod))%mod)+(res[i][j]%mod))%mod;
            }
        }
    }
    for(ll i=0;i<2;i++)
    {
        for(ll j=0;j<2;j++)
        {
            a[i][j]=res[i][j];
        }
    }
}
void power(ll** &mat,ll p)
{
	ll **res=new ll*[2];
    for(ll i=0;i<2;i++)
    {
        res[i]=new ll[2];
        for(ll j=0;j<2;j++)
        {
            if(i==j)
            {
                res[i][j]=1;
            }else{
                res[i][j]=0;
            }
        }
    }
    while(p!=0)
    {
        if(p%2!=0)
        {
            //res=res*mat;
            multiply(res,mat);
            p--;
        }else{
            //mat=mat*mat;
            multiply(mat,mat);
            p=p/2;
        }
    }
    for(ll i=0;i<2;i++)
    {
        for(ll j=0;j<2;j++)
        {
            mat[i][j]=res[i][j];
        }
    }
}
unsigned long long fib(unsigned long long n)
{
    ll **mat=new ll*[2];
    for(ll i=0;i<2;i++)
    {
        mat[i]=new ll[2];
    }
    mat[0][0]=0;
    mat[1][1]=1;
    mat[0][1]=1;
    mat[1][0]=1;
    power(mat,n);
    return mat[1][0];
}

unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
	return ((fib(n+2)%mod)-(fib(m+1)%mod)+mod)%mod;    
}













