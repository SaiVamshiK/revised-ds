#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int i=0,j=0;
	int curSum=0;
	int len=0;
	while(j<n)
	{
		curSum+=a[j];
		if(curSum<k)
		{
			j++;
		}else if(curSum==k)
		{
			len=max(len,j-i+1);
			j++;
		}else{
			while(curSum>k)
			{
				curSum-=a[i];
				i++;
			}
			if(curSum==k)
			{
				len=max(len,j-i+1);
			}
			j++;
		}
	}
	cout<<len;
}











