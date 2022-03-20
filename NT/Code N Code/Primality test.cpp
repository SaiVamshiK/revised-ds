#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)      substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x)        cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());




int32_t main()
{
  FIO;
	int t;
	cin>>t;
	int size=pow(10,5);
	bool *sieve=new bool[size+1];
	for(int i=0;i<=size;i++)
	{
		sieve[i]=true;
	}
	sieve[0]=false;
	sieve[1]=false;
	for(int i=2;(i*i)<=size;i++)
	{
		if(sieve[i])
		{
			int elem=i,mul=i;
			while((elem*mul)<=size)
			{
				sieve[(elem*mul)]=false;
				mul++;
			}
		}
	}
	while(t--)
	{
		int n;
		cin>>n;
		if(sieve[n])
		{
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
}
