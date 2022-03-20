
You are given a one dimensional array that may contain both positive and negative integers, 
find the sum of contiguous subarray of numbers which has the largest sum. For example, if the 
given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7. NOTE:- 
please solve this problem using Divide and Conquer instead of kadane's algorithm.

Input Format
The first line consists of number of test cases T. Each test case consists of N followed by N integers.

Constraints
1 <= N <= 100000 1 <= t <= 20 0 <= A[i] <= 100000000

Output Format
The maximum subarray sum

Sample Input
2
4
1 2 3 4
3
-10 5 10
Sample Output
10
15

ALgo:
	We divide the array into 2 parts recursively and at every step we choose for the max sum subarray as either the 
	max subarray sum in the left half or max subarray sum in the right half or the max sum subarray by combining the
	2 halves.

#include<bits/stdc++.h>
using namespace std;
int mergedMax(int *a,int start,int mid,int end)
{
	// Left => start - mid
	// Right => mid+1 - end
	int left_suffix=INT_MIN,right_prefix=INT_MIN;
	int cur=0;
	for(int i=mid;i>=start;i--)
	{
		cur=cur+a[i];
		left_suffix=max(left_suffix,cur);
	}
	cur=0;
	for(int i=mid+1;i<=end;i++)
	{
		cur+=a[i];
		right_prefix=max(right_prefix,cur);
	}
	return max(left_suffix,max(right_prefix,left_suffix+right_prefix));
}
int func(int *a,int start,int end,int &ans)
{
	if(start>end)
	{
		return INT_MIN;
	}
	if(start==end)
	{
		ans=max(ans,a[start]);
		return a[start];
	}
	int mid=start+((end-start)/2);
	int left_max=func(a,start,mid,ans);
	int right_max=func(a,mid+1,end,ans);
	int merge_max=mergedMax(a,start,mid,end);
	ans=max(ans,max(left_max,max(right_max,merge_max)));
	return max(left_max,max(right_max,merge_max));
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
		int ans=INT_MIN;
		func(a,0,n-1,ans);
		cout<<ans<<endl;
	}
}
