
Print single integer — the last digit of 1378^n.


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power(ll a,ll n,ll p)
{
    ll res=1;
    while(n!=0)
    {
        if(n%2==0)
        {
            a=(((a%p)*(a%p))%p);
            n=n/2;
        }else{
            res=((res%p)*(a%p))%p;
            n--;
        }
    }
    return res%p;
}
int main()
{
	ll n;
	cin>>n;
    ll ans=power(8,n,10);
    cout<<ans;
}




