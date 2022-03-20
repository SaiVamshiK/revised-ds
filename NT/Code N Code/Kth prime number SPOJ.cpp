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


The problem statement is really simple. There are some queries. You are to give the answers.

Input
An integer stating the number of queries Q(equal to 50000), and Q lines follow, each containing one integer K between 1 and 5000000 
inclusive.

Output
Q lines with the answer of each query: the Kth prime number.

int32_t main()
{
  FIO;
	int size=87000008;
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
	vector<int> primes;
	for(int i=0;i<=size;i++)
	{
		if(sieve[i])
		{
			primes.push_back(i);
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int k;
		cin>>k;
		cout<<primes[k-1]<<endl;
	}
}
