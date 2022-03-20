
https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem

#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
vector<string> split_string(string);
typedef long long ll;
// Complete the solve function below.
void multiply(ll** &a,ll** b)
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
                res[i][j]+=(((((ll)a[i][k]%mod)*((ll)b[k][j]%mod)))%mod);
                res[i][j]%=mod;
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
    }
    res[0][0]=1;
    res[1][1]=1;
    res[1][0]=0;
    res[0][1]=0;
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
int solve(int a, int b, int n) {
    ll **mat=new ll*[2];
    for(ll i=0;i<2;i++)
    {
        mat[i]=new ll[2];
    }
    mat[0][0]=0;
    mat[0][1]=1;
    mat[1][0]=1;
    mat[1][1]=1;
    power(mat,n);
    return (((a%mod)*(mat[0][0]%mod)%mod)+(((b%mod)*(mat[1][0]%mod))%mod))%mod;
}

