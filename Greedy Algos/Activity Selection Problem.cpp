
You are actually very busy man. You have a big schedule of activities. Your aim is to do as much as activities as possible.
In the given figure, if you go to date with crush, you cannot participate in the coding contest and you can’t watch the movie. Also 
if you play DotA, you can’t study for the exam. If you study for the exam you can’t sleep peacefully. The maximum number of activities 
that you can do for this schedule is 3. 

Either you can

watch movie, play DotA and sleep peacefully (or)
date with crush, play DotA and sleep peacefully
Input Specifications
The first line consists of an integer T, the number of test cases. For each test case the first line consists of an integer N, the 
number of activities. Then the next N lines contains two integers m and n, the start and end time of each activity.

Output Specifications
For each test case find the maximum number of activities that you can do.

#include<bits/stdc++.h>
using namespace std;
struct node{
	int start,end;
};
bool comparator(node a,node b)
{
	return a.end<b.end;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		node *a=new node[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i].start>>a[i].end;
		}
		sort(a,a+n,comparator);
		int cnt=1,last_end=a[0].end;
		for(int i=1;i<n;i++)
		{
			if(a[i].start>=last_end)
			{
				last_end=a[i].end;
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
}
