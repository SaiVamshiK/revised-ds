#include<bits/stdc++.h>
using namespace std;
bool func(int *a,int n,int k,vector<int> &dp)
{
	if(k==0)
	{
		return false;
	}
	if(k<0)
	{
		return true;
	}
    if(dp[k]!=-1)
    {
        return dp[k];
    }
	for(int i=0;i<n;i++)
	{
		bool f1=func(a,n,k-a[i],dp);
		if(f1==false)
		{
			return dp[k]=true;
		}
	}
	return dp[k]=false;
}
int main()
{
	int n,k;
	cin>>n>>k;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
    vector<int> dp(k+1,-1);
	if(func(a,n,k,dp))
    {
        cout<<"First";
    }else{
        cout<<"Second";
    }
}
