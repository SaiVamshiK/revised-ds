
Given a collection of numbers containing duplicates, print all possible permutations for the given collection of numbers in a lexicographic manner. Make sure that no two permutations are same.
NOTE: Try doing it without using SET or MAP!

Input Format
The first line will contain the number of elements, N in the array.
The second line will contain N elements of the array, A[i].

Constraints
1<= N <= 10 0 <= A[i] <= 100000

Output Format
Print all unique lexicographic permutations of the array. Each permutation will contain space separated elements. The next permutation should be printed in a new line.

Sample Input
3
1 1 3
Sample Output
1 1 3 
1 3 1 
3 1 1 

#include<bits/stdc++.h>
using namespace std;
void func(vector<int> &inp,vector<int> &op,bool *visited,int n,vector<vector<int>> &ans)
{
	if(op.size()==n)
	{
		ans.push_back(op);
		return ;
	}
	int prev=-1;
	for(int i=0;i<n;i++)
	{
		int cur=inp[i];
		if(!visited[i]&&(cur!=prev))
		{
			visited[i]=true;
			op.push_back(cur);
			func(inp,op,visited,n,ans);
			op.pop_back();
			visited[i]=false;
            prev=cur;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int> a(n,-1);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	bool *visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	vector<vector<int>> ans;
	vector<int> op;
	func(a,op,visited,n,ans);
	for(int i=0;i<(ans.size());i++)
	{
		for(int j=0;j<(ans[i].size());j++)
		{
			cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}
}















