
Deepak has a limited amount of money that he can spend on his girlfriend. So he decides to buy two roses for her. Since roses are of varying sizes, their prices are different. Deepak wishes to completely spend that fixed amount of money on buying roses for her.
As he wishes to spend all the money, he should choose a pair of roses whose prices when summed up are equal to the money that he has.
Help Deepak choose such a pair of roses for his girlfriend.

NOTE: If there are multiple solutions print the solution that minimizes the difference between the prices i and j. After each test case, you must print a blank line.

Input Format
The first line indicates the number of test cases T.
Then, in the next line, the number of available roses, N is given.
The next line will have N integers, representing the price of each rose, a rose that costs less than 1000001.
Then there is another line with an integer M, representing how much money Deepak has.
There is a blank line after each test case.

Constraints
1= T =100
2 = N = 10000
Price[i]<1000001

Output Format
For each test case, you must print the message: ‘Deepak should buy roses whose prices are i and j.’, where i and j are the prices of the roses whose sum is equal do M and i = j. You can consider that it is always possible to find a solution. If there are multiple solutions print the solution that minimizes the difference between the prices i and j.

Sample Input
2
2
40 40
80

5
10 2 6 8 4
10
Sample Output
Deepak should buy roses whose prices are 40 and 40.
Deepak should buy roses whose prices are 4 and 6.

Algo Used:
*We need to find a pair so that it sums upto a given value and then find a pair whose diff is min among all available.
*So for every element we find its corresponding value by substracting it from the sum so that we know that it is the
*element we are looking for then to see whether that element is there or not do a BS (for that initially sort the array)

#include<bits/stdc++.h>
using namespace std;
bool find(int *a,int start,int end,int key)
{
	while(start<=end)
	{
		int mid=start+((end-start)/2);
		if(a[mid]==key)
		{
			return true;
		}
		if(a[mid]>key)
		{
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	return false;
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
		int sum;
		cin>>sum;
		sort(a,a+n);
		int diff=INT_MAX;
		int val1,val2;
		for(int i=0;i<n;i++)
		{
			int cur=a[i];
			int key=sum-cur;
			if(((i+1<n)&&find(a,i+1,n-1,key))||((i-1>=0)&&find(a,0,i-1,key)))
			{
                int cur_diff=abs(key-cur);
				if((cur_diff)<diff)
				{
                    diff=cur_diff;
					val1=cur;
					val2=(sum-val1);
				}
			}
		}
		if(val1>val2)
		{
			swap(val1,val2);
		}
		cout<<"Deepak should buy roses whose prices are "<<val1<<" and "<<val2<<"."<<endl;
	}
}







