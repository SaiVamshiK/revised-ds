 
IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. 
The subcommittee members are asked to go to food connection and get P(P<=1000) pratas packed for the function. 
The stall has L cooks(L<=50) and each cook has a rank R(1<=R<=8). A cook with a rank R can cook 1 prata in the 
first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on(he can only cook a 
complete prata) ( For example if a cook is ranked 2.. he will cook one prata in 2 minutes one more prata in the 
next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he 
can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the minimum 
time to get the order done. Please write a program to help him out.

 

Input
The first line tells the number of test cases. Each test case consist of 2 lines. In the first line of the test 
case we have P the number of prata ordered. In the next line the first integer denotes the number of cooks L 
and L integers follow in the same line each denoting the rank of a cook.

Output
Print an integer which tells the number of minutes needed to get the order done.

#include<bits/stdc++.h>
using namespace std;
bool isValid(int timeVal,int *a,int n,int p)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int rank=a[i];
		int cur_time=0;
		int idx=1;
		while(true)
		{
			if(cur_time+(idx*rank)>timeVal)
			{
				break;
			}
			cur_time=cur_time+(idx*rank);
			idx++;
			cnt++;
		}
		if(cnt>=p)
		{
			return true;
		}
	}
	return cnt>=p;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int p;
		cin>>p;
		int r;
		cin>>r;
		int *a=new int[r];
		int minElem=INT_MAX;
		for(int i=0;i<r;i++)
		{
			cin>>a[i];
			minElem=min(minElem,a[i]);
		}
		int start=0,end=minElem*(p*(p+1))/2;
		int ans=end;
		while(start<=end)
		{
			int mid=start+((end-start)/2);
			if(isValid(mid,a,r,p))
			{
				ans=mid;
				end=mid-1;
			}else{
				start=mid+1;
			}
		}
		cout<<ans<<endl;
	}
}
