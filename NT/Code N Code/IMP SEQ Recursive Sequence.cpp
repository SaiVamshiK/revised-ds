

Sequence (ai) of natural numbers is defined as follows:

   ai = bi (for i <= k)
   ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)

where bj and cj are given natural numbers for 1<=j<=k. Your task is to compute an for given n and output it modulo 109.

#include<bits/stdc++.h>
using namespace std;
const int mod=1e9;
typedef long long ll;
void multiply(ll** &a,ll** b,int k)
{
    ll **res=new ll*[k];
    for(ll i=0;i<k;i++)
    {
        res[i]=new ll[k];
        for(ll j=0;j<k;j++)
        {
            res[i][j]=0;
        }
    }    
    for(ll i=0;i<k;i++)
    {
        for(ll j=0;j<k;j++)
        {
            for(ll q=0;q<k;q++)
            {
                res[i][j]+=(((((ll)a[i][q]%mod)*((ll)b[q][j]%mod)))%mod);
                res[i][j]%=mod;
            }
        }
    }
    for(ll i=0;i<k;i++)
    {
        for(ll j=0;j<k;j++)
        {
            a[i][j]=res[i][j];
        }
    }
}
void power(ll** &mat,ll p,ll k)
{
    ll **res=new ll*[k];
    for(ll i=0;i<k;i++)
    {
        res[i]=new ll[k];
        for(ll j=0;j<k;j++)
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
            multiply(res,mat,k);
            p--;
        }else{
            //mat=mat*mat;
            multiply(mat,mat,k);
            p=p/2;
        }
    }
    for(ll i=0;i<k;i++)
    {
        for(ll j=0;j<k;j++)
        {
            mat[i][j]=res[i][j];
        }
    }
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll k;
		cin>>k;
		ll *b=new ll[k];
		for(ll i=0;i<k;i++)
		{
			cin>>b[i];
		}
		ll *c=new ll[k];
		for(ll i=0;i<k;i++)
		{
			cin>>c[i];
		}
		ll n;
		cin>>n;
		ll **mat=new ll*[k];
		for(ll i=0;i<k;i++)
		{
			mat[i]=new ll[k];
			for(ll j=0;j<k;j++)
			{
				mat[i][j]=0;
			}
		}
		ll e=k-1;
		for(ll i=0;i<k;i++)
		{
			mat[i][k-1]=c[e--];
		}
		ll row=1,col=0;
		while((row<k)&&(col<k))
		{
			mat[row][col]=1;
			row++;col++;
		}
		
		power(mat,n-1,k);
		ll ans=0;
		for(ll i=0;i<k;i++)
		{
			ans+=(((b[i]%mod)*((mat[i][0]%mod)))%mod);
            ans%=mod;
		}
		cout<<ans<<endl;
	}
}
