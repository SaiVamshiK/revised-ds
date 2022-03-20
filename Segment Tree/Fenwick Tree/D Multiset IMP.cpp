#include<bits/stdc++.h>
using namespace std;
void ins(int *bit,int i,int n,int val)
{
	for(;i<=n;i+=(i&(-i)))
	{
		bit[i]+=val;
	}
}
int query(int *bit,int i)
{
	int cnt=0;
	for(;i>0;i-=(i&(-i)))
	{
		cnt+=bit[i];
	}
	return cnt;
}
int find(int *bit,int k,int size)
{
	int start=1,end=size;
	int ans=-1;
	while(start<=end)
	{
		int mid=(start)+((end-start)/2);
		int temp_ans=query(bit,mid);
		if(temp_ans>=k)
		{
			ans=mid;
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	int a;
	int size=pow(10,6);
	int *bit=new int[size+1];
	for(int i=0;i<=size;i++)
	{
		bit[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a;
		ins(bit,a,size,1);
	}
	while(q--)
	{
		int k;
		cin>>k;
		if(k>=1)
		{
			ins(bit,k,size,1);
		}else{
			k=abs(k);
			int kth_smallest=find(bit,k,size);
			ins(bit,kth_smallest,size,-1);
		}
	}
	int ans=find(bit,1,size);
	if(ans==-1)
	{
		cout<<0<<endl;
	}else{
		cout<<ans<<endl;
	}
}















