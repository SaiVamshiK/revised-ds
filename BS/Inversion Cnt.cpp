#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll merge(ll* &a,ll start,ll mid,ll end)
{
	// Left=> start - mid
	// Right=> mid+1 - end
	ll cnt=0;
	ll *temp=new ll[end-start+1];
	ll k=0;
	ll i=start,j=mid+1;
	while(i<=mid&&(j<=end))
	{
		if(a[i]<a[j])
		{
			temp[k++]=a[i++];
		}else{
			cnt+=(mid-i+1);
			temp[k++]=a[j++];
		}
	}
	while((i<=mid))
	{
		temp[k++]=a[i++];
	}
	while(j<=end)
	{
		temp[k++]=a[j++]; 
	}
    for(ll x=start,y=0;x<=end&&(y<=(end-start));x++,y++)
    {
        a[x]=temp[y];
    }
	return cnt;
}
ll countInversions(ll* &a,ll start,ll end)
{
	if(start>=end)
	{
		return 0;
	}
	ll mid=start+((end-start)/2);
	ll left_cnt=countInversions(a,start,mid);
	ll right_cnt=countInversions(a,mid+1,end);
	ll merge_cnt=merge(a,start,mid,end);
	return left_cnt+right_cnt+merge_cnt;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll *a=new ll[n];
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cout<<countInversions(a,0,n-1)<<endl;
	}
}
