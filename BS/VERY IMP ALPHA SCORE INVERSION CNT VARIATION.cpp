
You are climbing up using stairs where a number is written on each stair. At each step we define the alpha score as sum of all the numbers previously seen on the stairs which are smaller than the present number. Alpha score of the whole journey is defined as the sum of all the alpha scores at each step. Print the alpha score of whole journey modulus 1000000007.

Input Format
First line contains a single integer n denoting the number of stairs. Next line contains n space separated integers denoting the numbers written on stairs.

Constraints
1 <= n <= 10^5 Every number written on stair lies between [0,10^9]

Output Format
Single integer denoting the alpha score of the journey modulus 1000000007.

Sample Input
5
1 5 3 6 4
Sample Output
15

#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll mod=1000000007;
ll merge(ll* &a,ll start,ll mid,ll end)
{
    ll cnt=0;
	ll *temp=new ll[end-start+1];
	ll k=0;
	ll i=start,j=mid+1;
	while((i<=mid)&&(j<=end))
	{
		if(a[i]<a[j])
		{
			cnt+=((a[i]*(end-j+1)));
			cnt%=mod;
			temp[k++]=a[i++];
		}else{
			temp[k++]=a[j++];
		}
	}
	while(i<=mid)
	{
		temp[k++]=a[i++];
	}
	while(j<=end)
	{
		temp[k++]=a[j++];
	}
	for(ll x=start,y=0;x<=end;x++,y++)
	{
		a[x]=temp[y];
	}
	return cnt;
}
ll computeAlpha(ll* &a,ll start,ll end)
{
	if(start>=end)
	{
		return 0;
	}
	ll mid=start+((end-start)/2);
	ll left_cnt=computeAlpha(a,start,mid);
	ll right_cnt=computeAlpha(a,mid+1,end);
	ll merge_cnt=merge(a,start,mid,end);
	return ((left_cnt%mod)+(right_cnt%mod)+(merge_cnt%mod))%mod;
}
int main()
{
	ll n;
	cin>>n;
	ll *a=new ll[n];
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<computeAlpha(a,0,n-1)<<endl;
}
