
PMO gives two random numbers a & b to the Prime Minister. 
PM Modi wants to visit all countries between a and b (inclusive) , 
However due to shortage of time he can't visit each and every country , 
So PM Modi decides to visit only those countries,for which country number 
has two divisors. So your task is to find number of countries Mr. Modi will visit.


Input Format
The first line contains N , no of test cases. The next N lines contain two integers a and b denoting the range of country numbers.

Constraints
a<=1000000 & b<=1000000.
N<=1000

Output Format
Output contains N lines each containing an answer for the test case.

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int size=pow(10,6);
	bool *sieve=new bool[size+1];
	for(int i=0;i<=size;i++)
	{
		sieve[i]=true;
	}
	sieve[0]=false;
	sieve[1]=false;
	for(int i=2;(i*i)<=size;i++)
	{
		if(sieve[i])
		{
			int elem=i,mul=i;
			while((elem*mul)<=size)
			{
				sieve[(elem*mul)]=false;
				mul++;
			}
		}
	}
	int *arr=new int[size+1];
	for(int i=0;i<=size;i++)
	{
		arr[i]=0;
	}
	arr[2]=1;
	for(int i=3;i<=size;i++)
	{
		arr[i]+=arr[i-1];
		if(sieve[i])
		{
			arr[i]++;
		}
	}
	int n;
	cin>>n;
	while(n--)
	{
		int l,r;
		cin>>l>>r;
		cout<<(arr[r]-arr[(l-1)])<<endl;
	}
}


















