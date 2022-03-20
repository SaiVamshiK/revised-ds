#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll size=pow(10,5);
    bool *sieve=new bool[size+1];
    for(ll i=0;i<=size;i++)
    {
        sieve[i]=true;
    }
    sieve[0]=false;
    sieve[1]=false;
    for(ll i=2;(i*i)<=size;i++)
    {
        if(sieve[i])
        {
            ll elem=i,mul=i;
            while((elem*mul)<=size)
            {
                sieve[(elem*mul)]=false;
                mul++;
            }
        }
    }
    vector<ll> primes;
    for(ll i=0;i<=size;i++)
    {
        if(sieve[i])
        {
            primes.push_back(i);
        }
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        ll n=(r-l);
        bool *arr=new bool[n+1];
        for(ll i=0;i<=n;i++)
        {
            arr[i]=true;
        }
        for(ll i=0;(primes[i]*primes[i]<=r);i++)
        {
            ll cur_prime=primes[i];
            ll base=((l/cur_prime))*(cur_prime);
            if(base<l)
            {
                base+=cur_prime;
            }
            for(ll j=base;j<=r;j+=(cur_prime))
            {
                arr[(j-l)]=false;
            }
            if(base==cur_prime)
            {
                arr[(base-l)]=true;
            }
        }
        for(ll i=0;i<=n;i++)
        {
            if(arr[i])
            {
                cout<<(i+l)<<endl;
            }
        }
    }
	return 0;
}

