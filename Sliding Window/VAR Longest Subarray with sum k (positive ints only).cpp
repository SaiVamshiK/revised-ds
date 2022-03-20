#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int k;
	cin>>k;
	int i=0,j=0;
	int window_sum=0;
	int ans=INT_MIN;
	while(j<n)
	{
		window_sum+=a[j];
		if(window_sum<k)
		{
			j++;
		}else if(window_sum==k)
		{
			ans=max(ans,j-i+1);
			j++;
		}else if(window_sum>k)
		{
			while(window_sum>k)			
			{
				window_sum-=a[i];
				i++;
			}
			if(window_sum==k)
			{
				ans=max(ans,j-i+1);
			}
			j++;
		}
	}
	cout<<"Answer:"<<ans;
}






