#include<bits/stdc++.h>
using namespace std;
void update(int *bit,int i,int val,int n)
{
	for(;i<=n;i+=(i&(-i)))
	{
		bit[i]+=val;
	}
}
int query(int *bit,int i)
{
	int ans=0;
	for(;i>0;i-=(i&(-i)))
	{
		ans+=bit[i];
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,u;
		cin>>n>>u;
		int *bit=new int[10001];
		for(int i=0;i<=10000;i++)
		{
			bit[i]=0;
		}
		while(u--)
		{
			int l,r,val;
			cin>>l>>r>>val;
			l++;
			r++;
			update(bit,l,val,10000);
			update(bit,r+1,-val,10000);
		}
		int q;
		cin>>q;
		while(q--)
		{
			int idx;
			cin>>idx;
			idx++;
			cout<<query(bit,idx)<<endl;
		}
	}
}
