
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic subsequence
Input Constraints:
1<= N <= 100000
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5. 	
 	
 	
int longestBitonicSubarray(int *a, int n) {
	int *lis=new int[n];
    int *lds=new int[n];
    for(int i=0;i<n;i++)
    {
        lis[i]=1;
        lds[i]=1;
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
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,lds[i]+lis[i]-1);
    }
    return ans;
}


