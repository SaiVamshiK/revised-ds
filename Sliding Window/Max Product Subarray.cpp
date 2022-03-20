
Given an array Arr that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is 6, -3, -10 which gives product as 180.

class Solution{
public:

	long long maxi(long long a,long long b)
	{
	    if(a>b)
	    {
	        return a;
	    }
	    return b;
	}
	long long mini(long long a,long long b)
	{
	    if(a>b)
	    {
	        return b;
	    }
	    return a;
	}
	
	long long maxProduct(int *a, int n) {
	    long long max_eh=a[0],min_eh=a[0],ans=a[0];
	    for(int i=1;i<n;i++)
	    {
	        long long temp=max_eh;
	        max_eh=maxi(a[i],maxi(max_eh*(long long)a[i],min_eh*(long long)a[i]));
	        min_eh=mini(a[i],mini(min_eh*(long long)a[i],temp*(long long)a[i]));
	        ans=max(ans,max_eh);
	    }
	    return ans;
	}
};
