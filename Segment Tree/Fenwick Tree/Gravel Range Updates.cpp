
#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
typedef long long int ll;
void ins(ll *bit,ll i,ll val,ll n)
{
	for(;i<=n;i+=(i&(-i)))
	{
		bit[i]+=val;
	}
}
ll query(ll *bit,ll i)
{
	ll ans=0;
	for(;i>0;i-=(i&(-i)))
	{
		ans+=bit[i];
	}
	return ans;
}
int main()
{
    	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,q,x;
	cin>>n>>q>>x;
	ll *bit=new ll[n+1];
	for(ll i=0;i<=n;i++)
	{
		bit[i]=0;
	}
	while(q--)
	{
		char ch;
		cin>>ch;
		if(ch=='Q')
		{
			ll idx;
			cin>>idx;
			ll ans=query(bit,idx);
			cout<<(ans+x)<<endl;
		}else{
			ll l,r,inc;
			cin>>l>>r>>inc;
			ins(bit,l,inc,n);
			ins(bit,r+1,-inc,n);
		}
	}
}
