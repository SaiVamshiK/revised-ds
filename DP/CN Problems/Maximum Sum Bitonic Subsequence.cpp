Given an array of integers A. A subsequence of A is called Bitonic if it is first increasing then decreasing.

Input:
The first line contains an integer T denoting the no of test cases. Each test case consist of two lines. The first line contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A[].

Output:
For each test case in a new line print the max sum bitonic subsequence.


#include <bits/stdc++.h>
using namespace std;

int main() {
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
	    int *lis=new int[n];
	    int *lds=new int[n];
	    for(int i=0;i<n;i++)
	    {
	        lis[i]=a[i];
	        lds[i]=a[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	        int ans=0;
	        for(int j=0;j<i;j++)
	        {
	            if(a[i]>a[j])
	            {
	                ans=max(ans,lis[j]);
	            }
	        }
	        lis[i]+=ans;
	    }
	    for(int i=n-1;i>=0;i--)
	    {
	        int ans=0;
	        for(int j=i+1;j<n;j++)
	        {
	            if(a[i]>a[j])
	            {
	                ans=max(ans,lds[j]);
	            }
	        }
	        lds[i]+=ans;
	    }
	    int ans=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        ans=max(ans,lis[i]+lds[i]-a[i]);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}























