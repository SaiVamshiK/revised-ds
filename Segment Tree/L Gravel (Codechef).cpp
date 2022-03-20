
#include<bits/stdc++.h>
#define REP(i,n) for (ll i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<ll,ll>
#define vi vector<ll>
#define vii vector<ii>
#define lli long long ll
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
typedef long long ll;
void bt(ll *a,ll *tree,ll s,ll e,ll i)
{
	if(s==e)
	{
		tree[i]=a[s];
		return ;
	}
	ll mid=s+((e-s)/2);
	bt(a,tree,s,mid,(2*i));
	bt(a,tree,mid+1,e,(2*i)+1);
	tree[i]=(tree[(2*i)]+tree[(2*i)+1]);
	return ;
}
void update(ll *tree,ll *lazy,ll s,ll e,ll i,ll l,ll r,ll inc)
{
	if(lazy[i]!=0)
	{
		ll val=lazy[i];
		tree[i]+=(val*(e-s+1));
		if(s!=e)
		{
			lazy[(2*i)]+=val;
			lazy[(2*i)+1]+=val;
		}
		lazy[i]=0;
	}
	if(l>e||(r<s))
	{
		return ;
	}
	if((l<=s)&&(r>=e))
	{
		tree[i]+=((e-s+1)*inc);
		if(s!=e)
		{
			lazy[(2*i)]+=inc;
			lazy[(2*i)+1]+=inc;
		}
		return ;
	}
	ll mid=s+((e-s)/2);
	update(tree,lazy,s,mid,(2*i),l,r,inc);
	update(tree,lazy,mid+1,e,(2*i)+1,l,r,inc);
	tree[i]=(tree[(2*i)]+tree[(2*i)+1]);
}
ll query(ll *tree,ll *lazy,ll s,ll e,ll i,ll l,ll r)
{
	if(lazy[i]!=0)
	{
		ll val=lazy[i];
		tree[i]+=(val*(e-s+1));
		if(s!=e)
		{
			lazy[(2*i)]+=val;
			lazy[(2*i)+1]+=val;
		}
		lazy[i]=0;
	}
	if(l>e||(r<s))
	{
		return 0;
	}
	if((l<=s)&&(r>=e))
	{
		return tree[i];
	}
	ll mid=s+((e-s)/2);
	ll ans1=query(tree,lazy,s,mid,(2*i),l,r);
	ll ans2=query(tree,lazy,mid+1,e,(2*i)+1,l,r);
	return ans1+ans2;
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,q,x;
	cin>>n>>q>>x;
	ll *a=new ll[n];
	for(ll i=0;i<n;i++)
	{
		a[i]=x;
	}
	ll *tree=new ll[(4*n)+1];
	bt(a,tree,0,n-1,1);
	ll *lazy=new ll[(4*n)+1];
	for(ll i=0;i<=(4*n);i++)
	{
		lazy[i]=0;
	}
	while(q--)
	{
		char ch;
		cin>>ch;
		if(ch=='S')
		{
			ll l,r,val;
			cin>>l>>r>>val;
			l--;r--;
			update(tree,lazy,0,n-1,1,l,r,val);
		}else{
			ll l;
			cin>>l;
			l--;
			ll r=l;
			ll ans=query(tree,lazy,0,n-1,1,l,r);
			cout<<ans<<endl;
		}
	}
}
