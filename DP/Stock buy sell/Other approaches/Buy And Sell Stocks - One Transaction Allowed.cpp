
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed a single transaction.
Input Format
A number n
.. n more elements
Output Format
A number representing the maximum profit you can make if you are allowed a single transaction.

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
	int minVal=a[0];
	int maxProfit=0;
	for(int i=1;i<n;i++)
	{
	    maxProfit=max(maxProfit,a[i]-minVal);
	    minVal=min(minVal,a[i]);
	}
	cout<<maxProfit;
}


