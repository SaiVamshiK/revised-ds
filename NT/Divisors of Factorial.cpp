
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int main(){
	ll t;
    cin>>t;
    bool *sieve=new bool[50001];
    for(ll i=0;i<=50000;i++)
    {
        sieve[i]=true;
    }
    sieve[0]=false;
    sieve[1]=false;
    for(ll i=2;(i*i)<=50000;i++)
    {
        if(sieve[i])
        {
            ll elem=i,mul=i;
            while((elem*mul)<=50000)
            {
                sieve[(elem*mul)]=false;
                mul++;
            }
        }
    }
    while(t--)
    {
		ll n;
        cin>>n;
        ll ans=1;
        for(ll i=2;i<=n;i++)
        {
            if(sieve[i])
            {
                ll p=i,x=1;
                ll temp=0;
                while(pow(p,x)<=n)
                {
                    temp=temp+((n/pow(p,x)));
                    x++;
                }
                ans=((ans%MOD)*((temp+1)%MOD))%MOD;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}












