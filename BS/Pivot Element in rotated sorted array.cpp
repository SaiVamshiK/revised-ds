
You are given a sorted but rotated array. 
You need to fine the index of the pivot element of the array where pivot is that element 
in the array which is greater than its next element and divides the array into two monotonically increasing halves.

Input Format
The first line denotes N - the size of the array. The following N lines each denote the numbers in the array.

Constraints
Output Format
Output the index of the pivot of the array.

Sample Input
5
4
5
1
2
3
Sample Output
1
Explanation
Here, 5 is the pivot element. Thus the output is 1 which is 5's index.


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
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		if(a[0]<a[1])
		{
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	int idx=-1;
	int start=0,end=n-1;
	while(start<=end)
	{
		int mid=start+((end-start)/2);
		int left=((mid-1+n)%n),right=((mid+1)%n);
		if((a[left]>a[mid])&&(a[mid]<a[right]))
		{
			idx=mid;
			break;
		}
		// Left Unsorted left=> {start,mid}
		if(a[start]>a[mid])
		{
			end=mid;
		}
		// Righ Unsorted right=> {mid+1,end}
		else{
			start=mid;
		}
	}
	idx=((idx-1+n)%n);
	cout<<idx;
	return 0;
}





