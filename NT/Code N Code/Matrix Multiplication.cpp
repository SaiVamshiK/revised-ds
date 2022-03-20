

You will be given a square matrix M and a positive integer power N. You will have to compute M raised to the power N. 
(that is, M multiplied with itself N times.)

Input
First line of input is T ( number of test-cases) First line of each test-case contains two integer M , N where M is size 
of square matrix that we have to exponent and N is the power to which we have to exponent 
Next M lines describe the input matrix. Each line contains exactly M elements corresponding to each array

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
void multiply(ll** &iden,ll **a,ll n)
{
	ll **res=new ll*[n];
	for(ll i=0;i<n;i++)
	{
		res[i]=new ll[n];
		for(ll j=0;j<n;j++)
		{
			res[i][j]=0;
		}
	}
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			for(ll k=0;k<n;k++)
			{
				res[i][j]+=(((ll)iden[i][k]%MOD)*((ll)a[k][j]%MOD))%MOD;
				res[i][j]%=MOD;
			}
		}
	}
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            iden[i][j]=res[i][j];
        }
    }
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,p;
		cin>>n>>p;
		ll **a=new ll*[n];
		ll **iden=new ll*[n];
		for(ll i=0;i<n;i++){
			a[i]=new ll[n];
			iden[i]=new ll[n];
			for(ll j=0;j<n;j++)
			{
				cin>>a[i][j];
				if(i==j)
				{
					iden[i][j]=1;
				}else{
					iden[i][j]=0;
				}
			}
		}
		if(p==0)
		{
			for(ll i=0;i<n;i++)
			{
				for(ll j=0;j<n;j++)
				{
					cout<<(iden[i][j])<<' ';
				}
				cout<<endl;
			}
			continue;
		}
		if(p==1)
		{
			for(ll i=0;i<n;i++)
			{
				for(ll j=0;j<n;j++)
				{
					cout<<(a[i][j])<<' ';
				}
				cout<<endl;
			}
			continue;
		}
		while(p!=0)
		{
			if(p%2==0)
			{
				multiply(a,a,n);
				p=p/2;
			}else{
				multiply(iden,a,n);
				p--;
			}
		}
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				cout<<(iden[i][j])<<' ';
			}
			cout<<endl;
		}
	}
}










