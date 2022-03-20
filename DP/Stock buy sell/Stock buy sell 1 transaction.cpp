
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
	int right_max=a[n-1];
	int maxProfit=INT_MIN;
	for(int i=n-2;i>=0;i--)
	{
		maxProfit=max(maxProfit,right_max-a[i]);
		right_max=max(right_max,a[i]);
	}
	cout<<maxProfit<<endl;
}
