
You are given N books, ith of which has Pi pages (Pi <= Pj, if i < j). You have to assign these N books to M students, such that each student has subsegment of books and the maximum number of pages assigned to a student is minimized.
You have to find the maximum number of pages, a student can have in this assignment of books.

Input Format
First line contains integers, N and M, denoting the number of books and number of students respectively. Next line contains N integers, denoting the number of pages in N books.

Constraints
1<=N<=10^5 1<=M<=N 1<=Pi<=10^9

Output Format
Print a single integer, denoting the answer.

Sample Input
4 2
10 20 30 40
Sample Output
60


#include<bits/stdc++.h>
using namespace std;
bool isValid(int *a,int n,int m,int maxVal)
{ 
	int cur=0,cnt=1;
	for(int i=0;i<n;i++)
	{
		cur=cur+a[i];
		if(cur>maxVal)
		{
			cur=0;
			if(a[i]>maxVal)
			{
				return false;
			}
			cnt++;
			cur+=a[i];
		}
		if(cnt>m)
		{
			return false;
		}
	}
	return cnt<=m;
}
int main()
{
	int n,m;
	cin>>n>>m;
	int *a=new int[n];
	int start=INT_MIN,end=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		start=max(start,a[i]);
		end+=a[i];
	}
	int ans=INT_MAX;
	while(start<=end)
	{
		int mid=start+((end-start)/2);
		if(isValid(a,n,m,mid))
		{
			ans=mid;
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
    cout<<ans<<endl;
}
