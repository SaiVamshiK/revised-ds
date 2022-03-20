#include<bits/stdc++.h>
using namespace std;
int kadaneAlgo(int *a,int n)
{
	int cur_sum=0,max_sum=INT_MIN;
	for(int i=0;i<n;i++)
	{
		cur_sum=cur_sum+a[i];
		max_sum=max(max_sum,cur_sum);
		if(cur_sum<0)
		{
			cur_sum=0;
		}
	}
	return max_sum;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int *a=new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cout<<kadaneAlgo(a,n)<<endl;
	}
}
