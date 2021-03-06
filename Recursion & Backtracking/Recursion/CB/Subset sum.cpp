
Mike is a very passionate about sets. Lately, he is busy solving one of the problems on sets. He has to find whether if the sum of any of the non-empty subsets of the set A is zero.

Input Format
The first line contains an integer T, which is the total number of test cases.
T test cases follow.
Each test case consists of two lines.
The first line consists of a single integer N, which is the number of elements present in the set A.
The second line contains N space separated integers denoting the elements of the set A.

Constraints
1 = T =10
1 = N = 4
-10^5 = A[i] = 10^5

Output Format
Print the answer for each testcase in a new line.
If the sum of any of the subset is zero, then print ?Yes? (without quotes) else print ?No?(without quotes).

Sample Input
1
4
1 3 2 -3
Sample Output
Yes
Explanation
The sum of the subset {3,-3} is zero.

#include<bits/stdc++.h>
using namespace std;
void func(int *a,int i,int n,int sum,bool &done,vector<int> &op)
{
	if(sum==0&&(op.size()!=0))
	{
		done=true;
		return ;
	}
	if(i==n)
	{
		return ;
	}
	int cur=a[i];
	op.push_back(cur);
	func(a,i+1,n,sum-cur,done,op);
	op.pop_back();
	if(done)
	{
		return ;
	}
	func(a,i+1,n,sum,done,op);
	if(done)
	{
		return ;
	}
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
		bool done=false;
		vector<int> op;
		func(a,0,n,0,done,op);
		if(done)
		{
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}
